import java.util.*;

public class NetworkDelayTime_743 {
    public int networkDelayTime(int[][] times, int n, int k) {
        // Build the graph as an adjacency list
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph.computeIfAbsent(u, x -> new ArrayList<>()).add(new int[]{v, w});
        }

        // Min-heap to keep track of the minimum time to reach each node
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        minHeap.offer(new int[]{0, k}); // (time from source to node, node)

        Map<Integer, Integer> minTimes = new HashMap<>();

        while (!minHeap.isEmpty()) {
            int[] top = minHeap.poll();
            int timeKToI = top[0], i = top[1];

            if (minTimes.containsKey(i)) continue; // Skip if the node is already visited

            minTimes.put(i, timeKToI);

            // Traverse neighbors
            if (graph.containsKey(i)) {
                for (int[] nei : graph.get(i)) {
                    int neiNode = nei[0], neiTime = nei[1];
                    if (!minTimes.containsKey(neiNode)) {
                        minHeap.offer(new int[]{timeKToI + neiTime, neiNode});
                    }
                }
            }
        }

        if (minTimes.size() == n) {
            int maxTime = 0;
            for (int time : minTimes.values()) {
                maxTime = Math.max(maxTime, time);
            }
            return maxTime;
        } else {
            return -1; // Not all nodes are reachable
        }
    }
}
