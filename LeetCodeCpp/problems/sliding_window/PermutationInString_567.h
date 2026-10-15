#pragma once
#include <string>
#include <array>

class PermutationInString_567 {
public:
    bool checkInclusion_fullCompare(const std::string& s1, const std::string& s2);

    bool checkInclusion_matchesCounter(const std::string& s1, const std::string& s2);

private:
    static void applyDelta(std::array<int, 26>& window,
                           const std::array<int, 26>& need,
                           int idx,
                           int delta,
                           int& matches);
};
