#pragma once
#include <string>
#include <array>

using namespace std;

class PermutationInString_567 {
public:
    // Sliding window + full 26-bucket compare each step.
    bool checkInclusion_fullCompare(string s1, string s2);

    // Sliding window + "matches" counter (O(1) update per step).
    bool checkInclusion_matchesCounter(string s1, string s2);

private:
    static void applyDelta(array<int, 26>& window,
                           const array<int, 26>& need,
                           int idx,
                           int delta,
                           int& matches);
};
