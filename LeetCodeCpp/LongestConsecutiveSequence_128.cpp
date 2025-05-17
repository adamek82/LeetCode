#include "LongestConsecutiveSequence_128.h"

int LongestConsecutiveSequence_128::longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int num : st) {
        // only start counting if 'num' is the beginning of a sequence
        if (st.find(num - 1) == st.end()) {
            int current = num;
            int streak = 1;

            // walk forward until the end of this consecutive run
            while (st.find(current + 1) != st.end()) {
                current++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}