#include "RotateArray_189.h"
#include <cstddef>
#include <numeric>
#include <utility>

using namespace std;

void RotateArray_189::rotate(vector<int>& nums, int k)
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
