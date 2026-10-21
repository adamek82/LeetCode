#pragma once
#include <array>
#include <cstddef>
#include <string>

class PermutationInString_567 {
public:
    bool checkInclusion_fullCompare(const std::string& s1, const std::string& s2);
    bool checkInclusion_matchesCounter(const std::string& s1, const std::string& s2);
    bool checkInclusion_requiredCounter(const std::string& s1, const std::string& s2);

private:
    static constexpr std::size_t AlphabetSize = 26;
    using FrequencyArray = std::array<int, AlphabetSize>;

    static void applyDelta(FrequencyArray& window,
                           const FrequencyArray& need,
                           std::size_t idx,
                           int delta,
                           std::size_t& matches);
};
