import java.util.ArrayDeque;
import java.util.Queue;

public class ShortestPathInBinaryMatrix_1091 {
    private static final int[][] DIRS = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
            return -1;
        }

        int n = grid.length;
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{0, 0});
        grid[0][0] = 1; // distance from start

        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int r = cell[0];
            int c = cell[1];
            int dist = grid[r][c];

            if (r == n - 1 && c == n - 1) {
                return dist;
            }

            for (int[] dir : DIRS) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                    continue;
                }

                if (grid[nr][nc] != 0) {
                    continue;
                }

                grid[nr][nc] = dist + 1;
                q.offer(new int[]{nr, nc});
            }
        }

        return -1;
    }
}
