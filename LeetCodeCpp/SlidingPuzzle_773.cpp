#include "SlidingPuzzle_773.h"
#include <string>
#include <queue>
#include <unordered_set>

/*
 * Sliding Puzzle (LeetCode 773)
 *
 * We are given a 2x3 board containing numbers 1..5 and one empty cell 0.
 * A move consists of swapping 0 with one of its 4-directionally adjacent tiles.
 * We need the minimum number of moves required to reach:
 *
 *     [[1,2,3],
 *      [4,5,0]]
 *
 * Core idea:
 *   Treat every board arrangement as a graph node (a state).
 *   Two states are connected if one legal move transforms one into the other.
 *   Since every move has equal cost = 1, Breadth-First Search (BFS) naturally
 *   finds the shortest path to the target state.
 *
 * State representation:
 *   The board is flattened into a 6-character string.
 *
 *       [a b c]        "abc..."
 *       [d e f]   ->   positions 0..5
 *
 *   Example:
 *       [[1,2,3],[4,0,5]]  ->  "123405"
 *
 * Why string representation works well here:
 *   - It is compact.
 *   - It is easy to hash in unordered_set.
 *   - Swapping tiles is simple.
 *   - The total number of possible states is tiny: 6! = 720.
 *
 * Adjacency of the zero position on a 2x3 board:
 *
 *   indices:
 *       0 1 2
 *       3 4 5
 *
 *   legal swaps:
 *       0 <-> 1,3
 *       1 <-> 0,2,4
 *       2 <-> 1,5
 *       3 <-> 0,4
 *       4 <-> 1,3,5
 *       5 <-> 2,4
 *
 * BFS procedure:
 *   1. Convert the input board into the start string.
 *   2. If we ever pop the target string from the queue, return its depth.
 *   3. For the current state:
 *        - locate '0',
 *        - generate all states reachable by one swap,
 *        - push only states not visited before.
 *   4. If BFS finishes without finding the target, the puzzle is unsolvable.
 *
 * Correctness sketch:
 *
 *   1. BFS explores states level by level.
 *      Level k contains exactly the states reachable in k moves from the start.
 *
 *   2. Whenever we generate a neighbor, it differs by exactly one valid move.
 *      Therefore every enqueued state is reachable in the recorded number of moves.
 *
 *   3. The first time BFS reaches the target, it must be with the minimum
 *      number of moves, because all smaller depths were fully explored earlier.
 *
 *   4. If the target is never reached, then no sequence of legal moves leads
 *      from the start state to the solved state, so returning -1 is correct.
 *
 * Complexity:
 *   - Number of states is at most 720.
 *   - For each state we inspect at most 3 neighbors.
 *
 *   Time:  O(720 * 3)  -> effectively O(1) for this fixed board size
 *   Space: O(720)      -> effectively O(1)
 */
int SlidingPuzzle_773::slidingPuzzle(vector<vector<int>>& board)
{
    string start;
    start.reserve(6);

    for (const auto& row : board) {
        for (int value : row) {
            start += char('0' + value);
        }
    }

    const string target = "123450";

    const vector<vector<int>> neighbors = {
        {1, 3},      // index 0
        {0, 2, 4},   // index 1
        {1, 5},      // index 2
        {0, 4},      // index 3
        {1, 3, 5},   // index 4
        {2, 4}       // index 5
    };

    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == target) {
            return steps;
        }

        const int zeroPos = static_cast<int>(current.find('0'));

        for (int nextPos : neighbors[zeroPos]) {
            string nextState = current;
            swap(nextState[zeroPos], nextState[nextPos]);

            if (!visited.count(nextState)) {
                visited.insert(nextState);
                q.push({nextState, steps + 1});
            }
        }
    }

    return -1;
}
