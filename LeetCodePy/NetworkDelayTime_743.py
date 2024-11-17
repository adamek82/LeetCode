from typing import List
import heapq

class NetworkDelayTime_743:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Build the graph as an adjacency list
        graph = {i: [] for i in range(1, n + 1)}
        for u, v, w in times:
            graph[u].append((v, w))

        # Min-heap to track the minimum time to reach each node
        min_heap = [(0, k)]  # (time from source to node, node)

        # Dictionary to store the minimum time to reach each node
        min_times = {}

        while min_heap:
            time, node = heapq.heappop(min_heap)

            # Skip if the node has already been visited
            if node in min_times:
                continue

            # Record the minimum time for the current node
            min_times[node] = time

            # Process neighbors
            for neighbor, weight in graph[node]:
                if neighbor not in min_times:
                    heapq.heappush(min_heap, (time + weight, neighbor))

        # If not all nodes are reachable, return -1
        if len(min_times) != n:
            return -1

        # Return the maximum time among all reachable nodes
        return max(min_times.values())