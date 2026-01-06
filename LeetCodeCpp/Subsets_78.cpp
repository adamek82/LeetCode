#include "Subsets_78.h"
#include <bit>
#include <vector>

/*
 * Approach (bitmask enumeration)
 * ------------------------------
 * For n elements there are 2^n subsets. Iterate mask from 0..(1<<n)-1 and
 * include nums[i] iff the i-th bit of mask is set. This naturally preserves
 * the original element order inside each subset and yields a deterministic
 * subset order overall (by mask).
 *
 * Complexity
 * ----------
 * Time  : O(n * 2^n)
 * Space : O(n) for a single subset being built (O(2^n) in the output)
 */
vector<vector<int>> Subsets_78::subsets_bitmask(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    const int total = 1 << n;

    vector<vector<int>> out;
    out.reserve(total);

    for (int mask = 0; mask < total; ++mask) {
        vector<int> cur;
        /*
         * Reserve exactly the final subset size: popcount(mask) == how many elements
         * this subset will contain.
         *
         * This avoids two issues of reserve(n):
         *  (1) Over-allocation: with move(cur) the vector’s capacity is moved too, so
         *      reserve(n) would store capacity==n for every subset, wasting memory.
         *  (2) Reallocations: reserving popcount(mask) still prevents growth reallocs
         *      while building cur, but without the blanket n-sized buffers.
         */
        cur.reserve(popcount((unsigned)mask));
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) cur.push_back(nums[i]);
        }
        out.push_back(move(cur));
    }
    return out;
}

/*
 * Recursive backtracking — include/exclude with forward start
 * -----------------------------------------------------------
 * Idea:
 *   Build subsets by exploring choices left-to-right. At each call we have:
 *     - 'start' index from which we may add more elements,
 *     - a 'partial_sol' vector with the elements chosen so far.
 *   We first push the current 'partial_sol' into the output (pre-order), then
 *   iterate i = start..n-1:
 *     - choose nums[i] (push_back),
 *     - recurse with start = i + 1,
 *     - backtrack (pop_back).
 *
 * Why this works:
 *   The 'start' pointer prevents duplicates (we never revisit indices < start).
 *   Each recursion frame contributes exactly one subset (the current prefix),
 *   so we emit 2^n subsets overall.
 *
 * Complexity:
 *   Time  : O(n * 2^n)        — each element participates in half of subsets
 *   Space : O(n) auxiliary     — recursion depth + the current partial subset
 */
static void subsetsDfs(const vector<int>& nums,
                       int start,
                       vector<int>& partial_sol,
                       vector<vector<int>>& out)
{
    out.push_back(partial_sol);         // record the current subset

    for (int i = start; i < static_cast<int>(nums.size()); ++i) {
        partial_sol.push_back(nums[i]); // choose
        subsetsDfs(nums, i + 1, partial_sol, out);
        partial_sol.pop_back();         // backtrack
    }
}

vector<vector<int>> Subsets_78::subsets_recursive(vector<int>& nums) {
    vector<vector<int>> out;
    vector<int> partial_sol;
    partial_sol.reserve(nums.size());
    subsetsDfs(nums, 0, partial_sol, out);
    return out;
}
