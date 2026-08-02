#include "PascalsTriangle_118.h"

/*
 * Pascal's Triangle (LeetCode 118)
 *
 * We generate the triangle row by row.
 *
 * Observations:
 *   - The triangle has exactly numRows rows.
 *   - Row i (0-based) has exactly i + 1 elements.
 *   - The first and last element of every row are always 1.
 *   - Every inner element is the sum of the two elements directly above it:
 *
 *         row[j] = prevRow[j - 1] + prevRow[j]
 *
 * Approach:
 *   - Pre-reserve the outer vector for numRows rows.
 *   - For each row i:
 *       * Create a vector<int> of size i + 1, initialized to 1.
 *         This immediately sets both boundary values correctly.
 *       * Fill only the inner positions [1 .. i-1] using the previous row.
 *       * Move the completed row into the result.
 *
 * Why this is efficient:
 *   - result.reserve(numRows) avoids repeated reallocations of the outer vector.
 *   - Each row is created directly with its final size, so we avoid repeated
 *     push_back growth inside the row as well.
 *   - Since the output itself contains 1 + 2 + ... + numRows = O(numRows^2)
 *     numbers, O(numRows^2) total work is optimal up to constant factors.
 *
 * Correctness sketch:
 *   - Base:
 *       Row 0 is [1], which is correct.
 *
 *   - Induction step:
 *       Assume row i-1 is correct.
 *       Then row i:
 *         - starts and ends with 1, which matches Pascal's triangle,
 *         - every inner entry is computed as the sum of the two values above,
 *           exactly by definition of Pascal's triangle.
 *       Therefore row i is correct.
 *
 *   - By induction, all generated rows are correct.
 *
 * Complexity:
 *   - Time:  O(numRows^2)
 *   - Space: O(numRows^2) for the returned triangle
 */
vector<vector<int>> PascalsTriangle_118::generate(int numRows)
{
    vector<vector<int>> result;
    result.reserve(numRows);

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; ++j) {
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        }

        result.push_back(move(row));
    }

    return result;
}
