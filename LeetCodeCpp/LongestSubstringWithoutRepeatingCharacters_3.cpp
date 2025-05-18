#include "LongestSubstringWithoutRepeatingCharacters_3.h"

int LongestSubstringWithoutRepeatingCharacters_3::lengthOfLongestSubstring(string s)
{
    int n = s.size();
    // last occurrence of each ASCII char; initialized to -1
    vector<int> last(256, -1);
    int best = 0;
    // window is s[i..j-1]
    for (int i = 0, j = 0; j < n; ++j) {
        unsigned char c = s[j];
        // if we've seen c inside the current window [i..j-1], move i
        if (last[c] >= i) {
            i = last[c] + 1;
        }
        // record/update last position of c
        last[c] = j;
        // update best length
        best = max(best, j - i + 1);
    }
    return best;
}