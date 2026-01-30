public final class TestCases {
    private TestCases() {}

    // 207. Course Schedule
    public record CourseSchedule_207_Case(int numCourses, int[][] prerequisites, boolean expected) {}

    // 1971. Find if Path Exists in Graph
    public record FindIfPathExistsInGraph_1971_Case(int n, int[][] edges, int source, int destination, boolean expected) {}

    // 200. Number of Islands
    public record NumberOfIslands_200_Case(char[][] grid, int expected) {}

    // 695. Max Area of Island
    public record MaxAreaOfIsland_695_Case(int[][] grid, int expected) {}

    // 743. Network Delay Time
    public record NetworkDelayTime_743_Case(int[][] times, int n, int k, int expected) {}

    // 1584. Min Cost to Connect All Points
    public record MinCostToConnectAllPoints_1584_Case(int[][] points, int expected) {}

    // 300. Longest Increasing Subsequence
    public record LongestIncreasingSubsequence_300_Case(int[] nums, int expected) {}

    // 210. Course Schedule II
    public record CourseScheduleII_210_Case(int numCourses, int[][] prerequisites, int[] expectedOrderOrEmpty) {
        public boolean expectCycle() { return expectedOrderOrEmpty == null || expectedOrderOrEmpty.length == 0; }
    }

    // Helper for validating the order for 210 (so we don't keep it as a lambda in TestsRunner)
    public static boolean isValidTopologicalOrder(int[] order, int numCourses, int[][] prerequisites) {
        if (order == null) return false;
        if (order.length != numCourses) return false;

        int[] pos = new int[numCourses];
        for (int i = 0; i < numCourses; i++) pos[i] = -1;

        for (int i = 0; i < order.length; i++) {
            int v = order[i];
            if (v < 0 || v >= numCourses) return false;
            if (pos[v] != -1) return false; // duplicate
            pos[v] = i;
        }

        for (int[] p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            if (pos[prereq] > pos[course]) return false;
        }
        return true;
    }
}
