import java.util.PriorityQueue;

public class MinCostToConnectAllPoints_1584 {
        public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        boolean[] inMST = new boolean[n]; // Tracks points included in MST
        PriorityQueue<Edge> minHeap = new PriorityQueue<>((a, b) -> a.cost - b.cost); // Min-heap for edges
        int result = 0; // Total cost of the MST
        int edgesUsed = 0; // Number of edges added to the MST

        // Start from the first point
        minHeap.offer(new Edge(0, 0));

        while (edgesUsed < n) {
            Edge current = minHeap.poll();
            int cost = current.cost;
            int point = current.point;

            // Skip if the point is already included in the MST
            if (inMST[point]) {
                continue;
            }

            // Include this point in the MST
            inMST[point] = true;
            result += cost;
            edgesUsed++;

            // Add all valid edges from this point to the heap
            for (int nextPoint = 0; nextPoint < n; nextPoint++) {
                if (!inMST[nextPoint]) {
                    int dist = manhattanDistance(points[point], points[nextPoint]);
                    minHeap.offer(new Edge(nextPoint, dist));
                }
            }
        }

        return result;
    }

    // Helper function to calculate Manhattan distance between two points
    private int manhattanDistance(int[] p1, int[] p2) {
        return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
    }

    // Helper class to represent an edge in the min-heap
    private static class Edge {
        int point;
        int cost;

        Edge(int point, int cost) {
            this.point = point;
            this.cost = cost;
        }
    }
}
