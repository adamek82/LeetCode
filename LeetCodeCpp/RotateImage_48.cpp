#include "RotateImage_48.h"

/*
 * In-place 90° Rotation — Transpose-then-Reverse  — Correctness Sketch
 *
 * Idea
 *   1. Transpose swaps A[i][j] and A[j][i] ➜ turns rows into columns.
 *   2. Reversing every row mirrors the matrix horizontally.
 *   3. Composition = quarter-turn clockwise.
 *
 * Invariant after transposition
 *   • For every i<j: entries (i,j) and (j,i) are exchanged exactly once.
 *
 * Invariant after row-reversal
 *   • Row i is reversed, so element that used to be at col j
 *     moves to col n-1-j.
 *
 * Consequence
 *   • Entry originally at (r,c) finally lands at (c, n-1-r) — i.e. the
 *     correct clockwise-rotated position.
 *
 * Complexity
 *   – Time:  O(n²)  (touch every cell twice)
 *   – Space: O(1)   (in-place swaps)
 */
void RotateImage_48::rotateTransposeReverse(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

/*
 * In-place 90° Rotation — Layer-by-Layer “Onion” Swapping  — Correctness Sketch
 *
 * Treat the square as ⟨⌈n/2⌉⌉ concentric shells.
 *   Outer loop (layer i)   : walks from the outside towards the centre.
 *   Inner loop (offset j)  : performs cyclic 4-way swap on the i-th layer.
 *
 * 4-cycle mapping
 *   (i,            j)  → (j,            n-1-i) →
 *   (n-1-i,        n-1-j) → (n-1-j,        i)   → back to start.
 *
 * Invariant
 *   • After processing layer i, all indices with min(row,col)=i are already
 *     in their final rotated places; inner layers remain untouched.
 *
 * Proof sketch
 *   – A 4-way swap places each of the four coordinates above into its
 *     clockwise successor, preserving values exactly once.
 *   – Iterating j from i to n-1-i-1 covers the whole perimeter without
 *     overlap, so the layer is fully rotated.
 *
 * Complexity
 *   – Time:  O(n²)  (each element moved exactly once)
 *   – Space: O(1)   (single temp variable)
 */
void RotateImage_48::rotateLayerSwap(vector<vector<int>>& matrix)
{
    int n = static_cast<int>(matrix.size());
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j]                 = matrix[n - j - 1][i];
            matrix[n - j - 1][i]         = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1]         = tmp;
        }
    }
}
