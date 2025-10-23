#include "LongestCommonSubsequence_1143.h"

/*
 * Problem: Longest Common Subsequence (LCS) — LeetCode 1143
 *
 * Algorithm (Bottom-Up Dynamic Programming):
 * ------------------------------------------
 * Let text1 length be m, text2 length be n. Define dp[i][j] as the length of
 * the LCS between the prefixes text1[0..i-1] and text2[0..j-1]. We build
 * dp for i = 0..m and j = 0..n with the following recurrence:
 *
 *   Base:
 *     dp[0][j] = 0 for all j (empty text1 has LCS 0 with any prefix of text2)
 *     dp[i][0] = 0 for all i (empty text2 has LCS 0 with any prefix of text1)
 *
 *   Transition:
 *     If text1[i-1] == text2[j-1]:
 *         dp[i][j] = dp[i-1][j-1] + 1
 *     Else:
 *         dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * The answer is dp[m][n].
 *
 * Intuition:
 *   At position (i, j), you either (1) match the characters (if equal) and
 *   extend the best LCS of the two shorter prefixes, or (2) you must skip
 *   one character — either from text1 or from text2 — and take the better
 *   of those two possibilities. The table ensures we consider both skips.
 *
 * Correctness (Optimal Substructure + Exhaustive Local Choices):
 * --------------------------------------------------------------
 * 1) If text1[i-1] == text2[j-1], any LCS of the two full prefixes must end
 *    with that character (you can always append a shared final character
 *    without harming optimality). Thus the LCS length equals
 *    1 + LCS(text1[0..i-2], text2[0..j-2]) = dp[i-1][j-1] + 1.
 *
 * 2) If text1[i-1] != text2[j-1], the last character of an optimal LCS
 *    cannot be both text1[i-1] and text2[j-1]. Therefore, any optimal LCS
 *    is entirely contained in one of:
 *       (a) text1[0..i-2] and text2[0..j-1], or
 *       (b) text1[0..i-1] and text2[0..j-2].
 *    Taking max(dp[i-1][j], dp[i][j-1]) covers both options; any longer
 *    subsequence would contradict optimality of those subproblems.
 *
 * By filling the table from smaller prefixes to larger (i.e., bottom-up), all
 * dependencies are computed before use. Thus dp[m][n] is the true LCS length.
 *
 * Time and Space:
 *   Time:  O(m * n) — every cell computed once.
 *   Space: O(m * n) for the 2D table.
 *
 * Space Optimization to O(min(m, n)):
 * -----------------------------------
 * The transition only uses the current row and the previous row. We can store
 * a single 1D array of length min(m, n) and update it left-to-right while
 * carrying the "diagonal" (dp[i-1][j-1]) in a temp variable:
 *
 *   Choose the shorter string as the columns (size = k = min(m, n)).
 *   Let curr[j] represent dp[i][j] for the current i, and prev[j] represent
 *   the previous row. For each i:
 *
 *       Set diag = 0   // this will track dp[i-1][j-1]
 *       For j from 1..k:
 *           tmp = curr[j]        // will become prev[j] in next iteration
 *           if a_char == b_char:
 *               curr[j] = diag + 1
 *           else:
 *               curr[j] = max(curr[j], curr[j-1]) // curr[j] is prev[j]
 *           diag = tmp
 *
 *   Answer is curr[k] at the end.
 *
 * Notes:
 *   - The above gives only the LENGTH in O(min(m, n)) space. Reconstructing
 *     the actual subsequence in O(min(m, n)) space is non-trivial and
 *     typically requires Hirschberg’s algorithm (divide & conquer) or storing
 *     backpointers, which reintroduces extra space.
 *
 * Why a Greedy Two-Pointer Fails (Counterexamples):
 * -------------------------------------------------
 * LCS does NOT have a greedy choice property. Any fixed local rule like
 * “whenever chars differ, always advance i” (or always advance j, or always
 * take the earliest matching occurrence) can block longer matches later.
 *
 * 1) “Match each text1 char at its earliest occurrence in text2”:
 *      text1 = "ABCBDAB"
 *      text2 = "BDCABA"
 *    Greedy can end with "AB" (length 2), while optimal LCS length is 4
 *    (e.g., "BCBA" or "BDAB").
 *
 * 2) “If mismatch, always advance i” (symmetrically, always advance j):
 *      text1 = "XMJYAUZ"
 *      text2 = "MZJAWXU"
 *    Always advancing i may yield "MZ" (length 2),
 *    always advancing j may yield "X" (length 1),
 *    but the true LCS has length 4 (e.g., "MJAU").
 *
 * 3) “Take the first equality you see, then continue”:
 *      text1 = "AXBYCZ"
 *      text2 = "ABCXYZ"
 *    Premature local matches force later skips. The optimal LCS has length 4
 *    (e.g., "AXYZ"); greedy choices often get stuck with shorter results.
 *
 * In all these cases, a two-pointer with a fixed tie-breaking rule ignores
 * one of the two essential branches (skip from text1 vs skip from text2).
 * Dynamic programming systematically explores both, guaranteeing optimality.
 */
int LongestCommonSubsequence_1143::longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();

    // DP table where dp[i][j] is the LCS of text1[0..i-1] and text2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Bottom-up DP
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                // Characters match, extend the LCS
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Characters don't match, take the maximum LCS excluding one character
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}