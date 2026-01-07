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
 * Recursive backtracking — DFS over combinations (prefix-based)
 * --------------------------------------------------------------
 * Idea:
 *   We enumerate all subsets by performing a depth-first search over
 *   *prefixes* of increasing index sequences.
 *
 *   At each recursion frame we have:
 *     - 'start'       : the first index that may still be chosen,
 *     - 'partial_sol': the current subset (prefix) built so far.
 *
 *   The current 'partial_sol' is emitted immediately (pre-order),
 *   then we try to extend it by choosing one of the remaining elements:
 *
 *     for i = start .. n-1:
 *       - append nums[i] to the prefix,
 *       - recurse with start = i + 1,
 *       - backtrack (pop the element).
 *
 *   There is no explicit "exclude" branch — skipping an element is
 *   implicitly handled by advancing 'i' in the loop.
 *
 * Traversal example (nums = [1, 2, 3]):
 *
 *   visit []           → emit []
 *   │
 *   ├─ add 1 → [1]     → emit [1]
 *   │   │
 *   │   ├─ add 2 → [1,2]   → emit [1,2]
 *   │   │   │
 *   │   │   └─ add 3 → [1,2,3] → emit [1,2,3]
 *   │   │
 *   │   └─ add 3 → [1,3]   → emit [1,3]
 *   │
 *   ├─ add 2 → [2]     → emit [2]
 *   │   │
 *   │   └─ add 3 → [2,3]   → emit [2,3]
 *   │
 *   └─ add 3 → [3]     → emit [3]
 *
 * Why this works:
 *   - The 'start' index enforces strictly increasing positions, so each
 *     subset is generated exactly once and duplicates are impossible.
 *   - Each recursion frame corresponds to exactly one subset (the current
 *     prefix), hence exactly 2^n subsets are emitted in total.
 *
 * Complexity:
 *   Time  : O(n * 2^n)     — each element appears in half of the subsets
 *   Space : O(n) auxiliary — recursion depth + current prefix (excluding output)
 */
void Subsets_78::subsetsDfs(const vector<int>& nums,
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
    const size_t n = nums.size();

    vector<vector<int>> out;
    /*
     * We generate exactly 2^n subsets, so reserving helps avoid repeated reallocations of `out`.
     * Guard: shifting by >= 64 (1ULL << n) is undefined behavior on typical 64-bit platforms.
     */
    if (n < 64) {
        out.reserve(1ULL << n);
    }

    vector<int> partial_sol;
    /*
     * The current subset can grow up to length n; reserving avoids reallocations while we push/pop
     * during backtracking (capacity stays stable across the recursion).
     */
    partial_sol.reserve(nums.size());

    subsetsDfs(nums, 0, partial_sol, out);
    return out;
}
