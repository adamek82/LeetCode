#include "Subsets_78.h"
#include <bit>
#include <vector>

/*
 * Approach — bitmask enumeration
 * ------------------------------
 * Idea:
 *   For n elements there are 2^n subsets. Treat each subset as an n-bit mask:
 *     - bit i == 1  => pick nums[i]
 *     - bit i == 0  => don't pick nums[i]
 *
 *   Iterate mask from 0 .. (1<<n)-1. For each mask, scan bits i=0..n-1 and
 *   append nums[i] iff the i-th bit is set. This preserves the original
 *   element order inside each subset and yields a deterministic subset order
 *   overall (sorted by mask value).
 *
 * Example (nums = [1, 2, 3], bits correspond to [1,2,3] from LSB to MSB):
 *
 *   mask  bits   picks
 *   ----  -----  -----------
 *    0    000    []
 *    1    001    [1]
 *    2    010    [2]
 *    3    011    [1,2]
 *    4    100    [3]
 *    5    101    [1,3]
 *    6    110    [2,3]
 *    7    111    [1,2,3]
 *
 * Why this works:
 *   - Every subset corresponds to exactly one bit pattern in [0 .. 2^n - 1].
 *   - Scanning bits left-to-right by index keeps the element order stable
 *     within each subset; increasing mask gives a deterministic output order.
 *
 * Complexity:
 *   Time  : O(n * 2^n)
 *   Space : O(n) auxiliary for building one subset (O(2^n) in the output)
 */
vector<vector<int>> Subsets_78::subsets_bitmask(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    const int total = 1 << n;

    vector<vector<int>> out;
    /*
     * We generate exactly 2^n subsets, so reserving helps avoid repeated reallocations of `out`.
     * Guard: shifting by >= 64 (1ULL << n) is undefined behavior on typical 64-bit platforms.
     *
     * Note: under LeetCode constraints (1 <= nums.length <= 10) this guard will never trigger,
     * but keeping it is good practice and makes the code robust beyond the problem limits.
     */
    if (n < 64) {
        out.reserve(total);
    }

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

vector<vector<int>> Subsets_78::subsets_recursive_prefix(vector<int>& nums) {
    const size_t n = nums.size();

    vector<vector<int>> out;
    /*
     * We generate exactly 2^n subsets, so reserving helps avoid repeated reallocations of `out`.
     * Guard: shifting by >= 64 (1ULL << n) is undefined behavior on typical 64-bit platforms.
     *
     * Note: under LeetCode constraints (1 <= nums.length <= 10) this guard will never trigger,
     * but keeping it is good practice and makes the code robust beyond the problem limits.
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

/*
 * Recursive backtracking — binary "Don't pick / Pick" (decision tree)
 * -------------------------------------------------------------------
 * Idea:
 *   We enumerate all subsets by walking a binary decision tree over indices.
 *   At each index i we choose:
 *     - Don't pick nums[i]  (do not append it),
 *     - Pick nums[i]        (append it).
 *
 *   At each recursion frame we have:
 *     - 'i'          : the current index to decide on,
 *     - 'partial_sol': the subset built so far.
 *
 *   We recurse first into the "Don't pick" branch, then into the "Pick" branch.
 *   Only when i reaches n (leaf) we emit the current subset.
 *
 * Traversal example (nums = [1, 2, 3])  [Don't pick first, then Pick]:
 *
 *   i=0 (1)
 *   ├─ Don't pick 1
 *   │   i=1 (2)
 *   │   ├─ Don't pick 2
 *   │   │   i=2 (3)
 *   │   │   ├─ Don't pick 3 → emit []
 *   │   │   └─ Pick 3       → emit [3]
 *   │   └─ Pick 2
 *   │       i=2 (3)
 *   │       ├─ Don't pick 3 → emit [2]
 *   │       └─ Pick 3       → emit [2,3]
 *   └─ Pick 1
 *       i=1 (2)
 *       ├─ Don't pick 2
 *       │   i=2 (3)
 *       │   ├─ Don't pick 3 → emit [1]
 *       │   └─ Pick 3       → emit [1,3]
 *       └─ Pick 2
 *           i=2 (3)
 *           ├─ Don't pick 3 → emit [1,2]
 *           └─ Pick 3       → emit [1,2,3]
 *
 * Why this works:
 *   - Each element gets an independent take/skip decision, so every subset
 *     corresponds to exactly one root-to-leaf path.
 *   - The recursion produces exactly 2^n leaves, hence exactly 2^n subsets.
 *
 * Complexity:
 *   Time  : O(n * 2^n)     — copying subsets at leaves dominates (n per subset)
 *   Space : O(n) auxiliary — recursion depth + current subset (excluding output)
 */
void Subsets_78::subsetsBinaryDfs(const vector<int>& nums,
                                 int i,
                                 vector<int>& partial_sol,
                                 vector<vector<int>>& out)
{
    if (i == static_cast<int>(nums.size())) {
        out.push_back(partial_sol); // record subset at the leaf
        return;
    }

    // Don't pick nums[i]
    subsetsBinaryDfs(nums, i + 1, partial_sol, out);

    // Pick nums[i]
    partial_sol.push_back(nums[i]);
    subsetsBinaryDfs(nums, i + 1, partial_sol, out);
    partial_sol.pop_back();
}

vector<vector<int>> Subsets_78::subsets_recursive_binary(vector<int>& nums)
{
    const size_t n = nums.size();

    vector<vector<int>> out;
    /*
     * We generate exactly 2^n subsets, so reserving helps avoid repeated reallocations of `out`.
     * Guard: shifting by >= 64 (1ULL << n) is undefined behavior on typical 64-bit platforms.
     *
     * Note: under LeetCode constraints (1 <= nums.length <= 10) this guard will never trigger,
     * but keeping it is good practice and makes the code robust beyond the problem limits.
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

    subsetsBinaryDfs(nums, 0, partial_sol, out);
    return out;
}
