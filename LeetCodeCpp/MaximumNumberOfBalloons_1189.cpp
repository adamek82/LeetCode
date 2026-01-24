#include "MaximumNumberOfBalloons_1189.h"
#include <array>
#include <limits>

/*
 * Fixed-size frequency counting for the word "balloon".
 *
 * We first build a frequency table freq[0..25] for all lowercase letters
 * in the input text (freq['a' - 'a'] counts 'a', freq['b' - 'a'] counts 'b', etc.).
 *
 * Next, we define a requirement vector need[0..25] that encodes how many times
 * each letter is needed to form one occurrence of the word "balloon":
 *   b:1, a:1, l:2, o:2, n:1, all other letters:0.
 *
 * To find how many times we can form "balloon", we compute for every letter
 * that is required (need[i] > 0) how many full copies it supports:
 *   freq[i] / need[i]
 * and take the minimum over all required letters. That minimum is the answer,
 * because it is the bottleneck letter (the one we run out of first).
 * If no required letter is present at all, we return 0.
 *
 * Time complexity:
 * Let n be the length of text. We do one pass over the string (O(n)) and
 * one pass over the fixed alphabet of 26 letters (O(26) = O(1)), so the
 * total time is O(n).
 *
 * Space complexity:
 * We use only two fixed-size arrays of length 26 and a couple of scalars,
 * so the space usage is O(1).
 */
int MaximumNumberOfBalloons_1189::maxNumberOfBalloons(string &text)
{
    array<int, 26> freq{};                // zero-initialized
    for (char c : text) freq[c - 'a']++;

    // Initialize the requirement vector using an immediately-invoked lambda.
    // This lets us build a non-trivial std::array (with specific counts for
    // 'b','a','l','o','n') in a small local scope and return it as a single
    // expression. The lambda constructs a zero-initialized array, sets the
    // needed entries, and returns it; the trailing () immediately invokes
    // the lambda, so its result is used to initialize `need`.
    const array<int, 26> need = []{
        array<int, 26> a{};               // requirement vector
        a['b' - 'a'] = 1;
        a['a' - 'a'] = 1;
        a['l' - 'a'] = 2;
        a['o' - 'a'] = 2;
        a['n' - 'a'] = 1;
        return a;
    }();

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < 26; ++i)
        if (need[i])
            ans = min(ans, freq[i] / need[i]);

    return ans == numeric_limits<int>::max() ? 0 : ans;
}
