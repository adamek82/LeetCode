#include "ProductOfArrayExceptSelf.h"
#include <vector>

/*
 * Product of Array Except Self — prefix * suffix (2 passes, O(1) extra space)
 *
 * Idea
 * ----
 * For each index i, we want:
 *   answer[i] = (product of nums[0..i-1]) * (product of nums[i+1..n-1])
 * without using division.
 *
 * Pass 1 (left-to-right): store prefix products in result[]
 * ---------------------------------------------------------
 * Maintain `prefix = product(nums[0..i-1])`.
 * Before including nums[i] into `prefix`, write `result[i] = prefix`.
 * Then update `prefix *= nums[i]`.
 * After this pass: result[i] == product of all elements strictly to the left of i.
 *
 * Pass 2 (right-to-left): multiply by suffix products on the fly
 * --------------------------------------------------------------
 * Maintain `suffix = product(nums[i+1..n-1])` while scanning from the end.
 * Multiply `result[i] *= suffix` to combine left and right products.
 * Then update `suffix *= nums[i]`.
 * After this pass: result[i] == (left product) * (right product).
 *
 * Complexity
 * ----------
 * Time:  O(n)   (two linear passes)
 * Space: O(1) extra (output array not counted; only `prefix` and `suffix`)
 *
 * Notes
 * -----
 * Works with zeros naturally:
 * - one zero => only the zero position gets product of all non-zero elements
 * - two+ zeros => all results are 0
 * Uses 32-bit `int` multiplication; if inputs can overflow int, use `long long`.
 */
vector<int> ProductOfArrayExceptSelf::productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    // Calculate prefix products
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Calculate suffix products and multiply with prefix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}