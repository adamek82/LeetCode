#include "ValidPalindrome_125.h"
#include <cctype>   // for std::tolower

/*
 * Valid Palindrome (LeetCode 125)
 *
 * Checks whether a given string is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Idea:
 *   - Use two pointers: one at the beginning (l) and one at the end (r).
 *   - Move l and r inward, skipping any characters that are not
 *     alphanumeric.
 *   - For each pair of characters that remain, compare them in
 *     lowercase form:
 *       - If they differ, the string is not a palindrome.
 *       - If they match, move both pointers inward and continue.
 *
 * Why static_cast<unsigned char> is used:
 *   - Functions like isalnum and tolower from <cctype> expect either:
 *       * EOF, or
 *       * an *unsigned char* value in the range of unsigned char.
 *   - If 'char' is signed on a platform and s[i] has a value > 127,
 *     then passing it directly (as a negative value) to isalnum/tolower
 *     results in undefined behavior.
 *   - By casting to unsigned char first, we guarantee that the argument
 *     is in the valid range for these functions and avoid UB.
 *
 * Complexity:
 *   - Time:  O(n) — each character is inspected at most once.
 *   - Space: O(1) — uses only a few extra variables.
 */
bool ValidPalindrome_125::isPalindrome(string s)
{
    int l = 0, r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        while (l < r && !isalnum(static_cast<unsigned char>(s[l]))) ++l;
        while (l < r && !isalnum(static_cast<unsigned char>(s[r]))) --r;
        if (l < r &&
            tolower(static_cast<unsigned char>(s[l])) !=
            tolower(static_cast<unsigned char>(s[r])))
            return false;
        ++l; --r;
    }
    return true;
}
