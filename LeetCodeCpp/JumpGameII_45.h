#pragma once
#include <vector>
using namespace std;

/*
 * LeetCode 45 — Jump Game II
 *
 * Greedy "level expansion" (BFS without a queue)
 * ------------------------------------------------
 * View every index i as a node and a directed edge i -> j for each j in
 * [i+1, i + nums[i]]. Because the input guarantees reachability of n-1,
 * the minimum number of jumps equals the number of BFS layers needed to
 * reach the last index.
 *
 * Instead of an explicit BFS, we expand layers with two integers:
 *   - jumps   : how many layers we have already fully expanded (answer so far)
 *   - curEnd  : the farthest index reachable using exactly `jumps` jumps
 *   - farthest: the farthest index reachable using `jumps + 1` jumps
 *
 * Invariant:
 *   After processing all indices i in the current layer (i.e., up to curEnd),
 *   `farthest` equals max(i + nums[i]) over that layer. Taking one more jump
 *   (jumps++) sets curEnd = farthest, i.e., we move to the next layer in one go.
 *
 * Algorithm (one pass):
 *   - Iterate i from 0 to n-2 (no need to process the last index).
 *   - Update farthest = max(farthest, i + nums[i]).
 *   - When i == curEnd, we've finished the current layer:
 *       ++jumps; curEnd = farthest;
 *
 * Optimality intuition:
 *   Each time we "must" take a jump (i hits curEnd), choosing the farthest
 *   point reachable from any index in the current layer minimizes the number
 *   of remaining layers — identical to BFS choosing all nodes of the next
 *   frontier at once.
 *
 * Edge cases:
 *   - n <= 1 -> 0 jumps.
 *   - Zeros inside the array are fine as long as reachability holds (per constraints).
 *
 * Complexity:
 *   Time O(n), Space O(1) extra.
 */
class JumpGameII_45 {
public:
    // Returns the minimum number of jumps to reach the last index.
    int jump(vector<int>& nums);
};
