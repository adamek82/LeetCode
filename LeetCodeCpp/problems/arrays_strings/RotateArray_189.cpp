#include "RotateArray_189.h"
#include <cstddef>
#include <numeric>
#include <utility>

using namespace std;

namespace {

// Intentionally avoid std::reverse to practice implementing range reversal.
void reverseRange(vector<int>& nums, size_t first, size_t last)
{
    while (first < last) {
        --last;
        if (first >= last)
            break;
        swap(nums[first], nums[last]);
        ++first;
    }
}

} // namespace

void RotateArray_189::rotateCycles(vector<int>& nums, int k)
{
    const size_t n = nums.size();
    if (n < 2)
        return;

    const size_t shift = static_cast<size_t>(k) % n;
    if (shift == 0)
        return;

    const size_t cycles = gcd(n, shift);

    for (size_t start = 0; start < cycles; ++start) {
        size_t current = start;
        int previous = nums[start];

        do {
            const size_t next = (current + shift) % n;
            swap(previous, nums[next]);
            current = next;
        } while (current != start);
    }
}

void RotateArray_189::rotateReverse(vector<int>& nums, int k)
{
    const size_t n = nums.size();
    if (n < 2)
        return;

    const size_t shift = static_cast<size_t>(k) % n;
    if (shift == 0)
        return;

    reverseRange(nums, 0, n);
    reverseRange(nums, 0, shift);
    reverseRange(nums, shift, n);
}

vector<int> RotateArray_189::rotateCopy(const vector<int>& nums, int k)
{
    const size_t n = nums.size();
    if (n == 0)
        return {};

    const size_t start = n - static_cast<size_t>(k) % n;
    vector<int> rotated;
    rotated.reserve(n);

    for (size_t i = start; i < n; ++i)
        rotated.push_back(nums[i]);

    for (size_t i = 0; i < start; ++i)
        rotated.push_back(nums[i]);

    return rotated;
}
