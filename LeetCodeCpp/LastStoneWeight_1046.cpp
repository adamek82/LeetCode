#include "LastStoneWeight_1046.h"
#include <queue>

int LastStoneWeight_1046::lastStoneWeight(const vector<int>& stones)
{
    priority_queue<int> pq(stones.begin(), stones.end()); // max-heap
    while (pq.size() > 1) {
        int y = pq.top(); pq.pop(); // heaviest
        int x = pq.top(); pq.pop(); // second heaviest
        if (y != x) pq.push(y - x);
    }
    return pq.empty() ? 0 : pq.top();
}