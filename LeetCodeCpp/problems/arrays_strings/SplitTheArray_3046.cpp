#include "SplitTheArray_3046.h"

// Core observation:
// Each value may appear at most twice. If any value appears 3+ times,
// one of the halves would be forced to contain a duplicate of that value.
// Conversely, when every frequency <= 2, we can always distribute:
// - give one copy to nums1, the second (if exists) to nums2,
// - then balance singles to reach size n/2 for each part.
bool SplitTheArray_3046::isPossibleToSplit(vector<int>& nums) {
    int cnt[101] = {0};
    for (int x : nums) {
        if (++cnt[x] > 2) return false;
    }
    return true;
}
