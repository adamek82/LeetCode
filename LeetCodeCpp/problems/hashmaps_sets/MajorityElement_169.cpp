#include "MajorityElement_169.h"

#include <bit>
#include <cstdint>
#include <unordered_map>

int MajorityElement_169::majorityElementBoyerMoore(const vector<int>& nums) const
{
    int candidate = nums.front();
    int count = 0;

    for (const int num : nums) {
        if (count == 0) {
            candidate = num;
        }

        count += num == candidate ? 1 : -1;
    }

    return candidate;
}

int MajorityElement_169::majorityElementHashmap(const vector<int>& nums) const
{
    unordered_map<int, size_t> frequencies;
    frequencies.reserve(nums.size());

    const size_t majorityThreshold = nums.size() / 2;

    for (const int num : nums) {
        const size_t frequency = ++frequencies[num];

        if (frequency > majorityThreshold) {
            return num;
        }
    }

    return nums.front();
}

int MajorityElement_169::majorityElementBitCounting(const vector<int>& nums) const
{
    constexpr size_t BIT_COUNT = 32;

    const size_t majorityThreshold = nums.size() / 2;
    uint32_t result = 0;

    for (size_t bit = 0; bit < BIT_COUNT; ++bit) {
        const uint32_t mask = uint32_t{1} << bit;
        size_t ones = 0;

        for (const int num : nums) {
            if ((static_cast<uint32_t>(num) & mask) != 0) {
                ++ones;
            }
        }

        if (ones > majorityThreshold) {
            result |= mask;
        }
    }

    return std::bit_cast<int32_t>(result);
}
