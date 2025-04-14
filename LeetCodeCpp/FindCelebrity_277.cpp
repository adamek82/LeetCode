#include "FindCelebrity_277.h"

int FindCelebrity_277::findCelebrity(int n)
{
    // Step 1: Find a candidate
    int candidate = 0;
    for (int i = 1; i < n; ++i) {
        if (knows(candidate, i)) {
            // candidate cannot be a celebrity
            candidate = i;
        }
        // else: i cannot be a celebrity, so skip
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < n; ++i) {
        if (i == candidate) continue;
        if (knows(candidate, i) || !knows(i, candidate)) {
            return -1;
        }
    }

    return candidate;
}