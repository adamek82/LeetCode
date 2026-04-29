import java.util.*;

public class NetworkDelayTime_743 {
    public int networkDelayTime(int[][] times, int n, int k) {
        final int INF = Integer.MAX_VALUE;

        // Build the graph as an adjacency list
        List<List<int[]>> graph = new ArrayList<>();

        // Nodes are numbered from 1 to n, so we allocate n + 1 entries.
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            graph.get(u).add(new int[] { v, w });
        }

        // Dijkstra
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[k] = 0;

        // State: {distance from source, node}
        // Min-heap to keep track of the minimum time to reach each node
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        minHeap.offer(new int[] { 0, k });

        while (!minHeap.isEmpty()) {
            int[] state = minHeap.poll();
            int d = state[0];
            int u = state[1];

            // This is an outdated heap entry.
            // A better distance to u has already been found.
            if (d > dist[u]) {
                continue;
            }

            for (int[] edge : graph.get(u)) {
                int v = edge[0];
                int w = edge[1];

                // Relaxation
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    minHeap.offer(new int[] { dist[v], v });
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            maxTime = Math.max(maxTime, dist[i]);
        }

        return maxTime == INF ? -1 : maxTime;
    }
}
