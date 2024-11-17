const { MinPriorityQueue } = require('datastructures-js');

/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var networkDelayTime = function(times, n, k) {
    // Build the adjacency list
    const graph = new Map();
    for (const [u, v, w] of times) {
        if (!graph.has(u)) graph.set(u, []);
        graph.get(u).push([v, w]);
    }

    // Min-heap to track the minimum time to reach each node
    const minHeap = new MinPriorityQueue(([node, time]) => time);
    minHeap.enqueue([k, 0]); // Start from node `k` with time 0

    // Track the shortest times to each node
    const minTimes = new Map();

    while (!minHeap.isEmpty()) {
        const [currentNode, currentTime] = minHeap.dequeue();

        if (minTimes.has(currentNode)) continue; // Skip if the node is already visited

        minTimes.set(currentNode, currentTime);

        // Process neighbors
        if (graph.has(currentNode)) {
            for (const [neighbor, time] of graph.get(currentNode)) {
                if (!minTimes.has(neighbor)) {
                    minHeap.enqueue([neighbor, currentTime + time]);
                }
            }
        }
    }

    // If not all nodes are reachable, return -1
    if (minTimes.size !== n) return -1;

    // Return the maximum time to reach any node
    return Math.max(...minTimes.values());
};

module.exports = networkDelayTime;