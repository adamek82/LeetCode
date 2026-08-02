#include "SlidingPuzzle_773.h"

#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

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

    // Adjacent positions for each index in the flattened 2x3 board:
    // 0 1 2
    // 3 4 5
    const vector<vector<int>> neighbors = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {1, 3, 5},
        {2, 4}
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
