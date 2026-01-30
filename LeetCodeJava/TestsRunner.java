import java.util.List;

public class TestsRunner {

    private static void courseSchedule_207_tests() {
        CourseSchedule_207 sol = new CourseSchedule_207();

        var cases = List.of(
            new TestCases.CourseSchedule_207_Case(2, new int[][]{{1, 0}}, true),
            new TestCases.CourseSchedule_207_Case(2, new int[][]{{1, 0}, {0, 1}}, false),
            new TestCases.CourseSchedule_207_Case(5, new int[][]{{0, 1}, {2, 3}, {3, 4}, {2, 1}}, true),
            new TestCases.CourseSchedule_207_Case(5, new int[][]{{0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2}}, false)
        );

        TestUtils.runCases(
            "CourseSchedule_207",
            cases,
            tc -> sol.canFinish(tc.numCourses(), tc.prerequisites()),
            TestCases.CourseSchedule_207_Case::expected
        );
    }

    private static void findIfPathExistsInGraph_1971_tests() {
        FindIfPathExistsInGraph_1971 sol = new FindIfPathExistsInGraph_1971();

        var cases = List.of(
            new TestCases.FindIfPathExistsInGraph_1971_Case(3, new int[][]{{0, 1}, {1, 2}, {2, 0}}, 0, 2, true),
            new TestCases.FindIfPathExistsInGraph_1971_Case(6, new int[][]{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false),
            new TestCases.FindIfPathExistsInGraph_1971_Case(4, new int[][]{{0, 1}, {1, 2}, {2, 3}}, 0, 3, true),
            new TestCases.FindIfPathExistsInGraph_1971_Case(5, new int[][]{{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true),
            new TestCases.FindIfPathExistsInGraph_1971_Case(4, new int[][]{{0, 1}, {1, 2}}, 0, 3, false)
        );

        TestUtils.runCases(
            "FindIfPathExistsInGraph_1971",
            cases,
            tc -> sol.validPath(tc.n(), tc.edges(), tc.source(), tc.destination()),
            TestCases.FindIfPathExistsInGraph_1971_Case::expected
        );
    }

    private static void numberOfIslands_200_tests() {
        NumberOfIslands_200 sol = new NumberOfIslands_200();

        var cases = List.of(
            new TestCases.NumberOfIslands_200_Case(new char[][]{
                {'1','1','1','1','0'},
                {'1','1','0','1','0'},
                {'1','1','0','0','0'},
                {'0','0','0','0','0'}
            }, 1),

            new TestCases.NumberOfIslands_200_Case(new char[][]{
                {'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
            }, 3),

            new TestCases.NumberOfIslands_200_Case(new char[][]{
                {'1','0','0','0','1'},
                {'0','1','1','1','0'},
                {'0','1','0','1','0'},
                {'1','0','0','0','1'}
            }, 5),

            new TestCases.NumberOfIslands_200_Case(new char[][]{
                {'1','1','1'},
                {'0','1','0'},
                {'1','1','1'}
            }, 1)
        );

        TestUtils.runCases(
            "NumberOfIslands_200",
            cases,
            tc -> sol.numIslands(GridUtils.copy(tc.grid())), // ważne: copy, bo sol może mutować
            TestCases.NumberOfIslands_200_Case::expected
        );
    }

    private static void maxAreaOfIsland_695_tests() {
        MaxAreaOfIsland_695 sol = new MaxAreaOfIsland_695();

        var cases = List.of(
            new TestCases.MaxAreaOfIsland_695_Case(new int[][]{
                {0,0,1,0,0,0,0,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,1,1,0,0,0,0}
            }, 6),

            new TestCases.MaxAreaOfIsland_695_Case(new int[][]{{0,0,0,0,0,0,0,0}}, 0),

            new TestCases.MaxAreaOfIsland_695_Case(new int[][]{
                {1,1,0,0,1,1},
                {1,0,0,0,1,1},
                {0,0,1,1,1,0},
                {0,0,1,0,1,1}
            }, 10),

            new TestCases.MaxAreaOfIsland_695_Case(new int[][]{
                {0,1,1,1},
                {1,1,0,0},
                {1,0,0,1},
                {1,1,1,0}
            }, 9)
        );

        TestUtils.runCases(
            "MaxAreaOfIsland_695",
            cases,
            tc -> sol.maxAreaOfIsland(GridUtils.copy(tc.grid())),
            TestCases.MaxAreaOfIsland_695_Case::expected
        );
    }

    private static void courseScheduleII_210_tests() {
        CourseScheduleII_210 sol = new CourseScheduleII_210();

        var cases = List.of(
            new TestCases.CourseScheduleII_210_Case(2, new int[][]{{1, 0}}, new int[]{0, 1}),
            new TestCases.CourseScheduleII_210_Case(4, new int[][]{{1, 0}, {2, 0}, {3, 1}, {3, 2}}, new int[]{0, 1, 2, 3}),
            new TestCases.CourseScheduleII_210_Case(1, new int[][]{}, new int[]{0}),
            new TestCases.CourseScheduleII_210_Case(6, new int[][]{{1, 0}, {2, 0}, {3, 4}, {5, 4}}, new int[]{0, 1, 2, 4, 3, 5}),
            new TestCases.CourseScheduleII_210_Case(5, new int[][]{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}, new int[]{})
        );

        System.out.println("Running CourseScheduleII_210 tests:");
        int pass = 0;

        for (int i = 0; i < cases.size(); i++) {
            var tc = cases.get(i);

            int[] order = sol.findOrder(tc.numCourses(), tc.prerequisites());
            boolean ok = tc.expectCycle()
                ? (order != null && order.length == 0)
                : TestCases.isValidTopologicalOrder(order, tc.numCourses(), tc.prerequisites());

            System.out.println("  Test " + (i + 1) + ": res = " + (ok ? "PASS" : "FAIL"));
            if (ok) pass++;
        }

        System.out.println("  => " + pass + "/" + cases.size() + " PASS");
        System.out.println();
    }

    private static void networkDelayTime_743_tests() {
        NetworkDelayTime_743 sol = new NetworkDelayTime_743();

        var cases = List.of(
            new TestCases.NetworkDelayTime_743_Case(new int[][]{{2,1,1},{2,3,1},{3,4,1}}, 4, 2, 2),
            new TestCases.NetworkDelayTime_743_Case(new int[][]{{1,2,1}}, 2, 1, 1),
            new TestCases.NetworkDelayTime_743_Case(new int[][]{{1,2,1}}, 2, 2, -1),
            new TestCases.NetworkDelayTime_743_Case(new int[][]{{1,2,2},{1,3,4},{2,4,7},{3,4,1},{2,5,5},{5,6,3},{4,6,2}}, 6, 1, 7),
            new TestCases.NetworkDelayTime_743_Case(new int[][]{{1,2,2},{1,3,1},{3,4,4},{2,5,7},{5,6,1},{6,7,5},{7,8,2},{4,8,3}}, 8, 1, 15)
        );

        TestUtils.runCases(
            "NetworkDelayTime_743",
            cases,
            tc -> sol.networkDelayTime(tc.times(), tc.n(), tc.k()),
            TestCases.NetworkDelayTime_743_Case::expected
        );
    }

    private static void minCostToConnectAllPoints_1584_tests() {
        MinCostToConnectAllPoints_1584 sol = new MinCostToConnectAllPoints_1584();

        var cases = List.of(
            new TestCases.MinCostToConnectAllPoints_1584_Case(new int[][]{{0,0},{2,2},{3,10},{5,2},{7,0}}, 20),
            new TestCases.MinCostToConnectAllPoints_1584_Case(new int[][]{{3,12},{-2,5},{-4,1}}, 18),
            new TestCases.MinCostToConnectAllPoints_1584_Case(new int[][]{{1,1},{3,3},{7,7},{10,10},{15,15}}, 28),
            new TestCases.MinCostToConnectAllPoints_1584_Case(new int[][]{{0,0},{1,1},{1,0},{0,1},{2,2}}, 5),
            new TestCases.MinCostToConnectAllPoints_1584_Case(new int[][]{{-100,-100},{100,100},{-100,100},{100,-100}}, 600)
        );

        TestUtils.runCases(
            "MinCostToConnectAllPoints_1584",
            cases,
            tc -> sol.minCostConnectPoints(GridUtils.deepCopyPoints(tc.points())),
            TestCases.MinCostToConnectAllPoints_1584_Case::expected
        );
    }

    private static void longestIncreasingSubsequence_300_tests() {
        LongestIncreasingSubsequence_300 sol = new LongestIncreasingSubsequence_300();

        var cases = List.of(
            new TestCases.LongestIncreasingSubsequence_300_Case(new int[]{10,9,2,5,3,7,101,18}, 4),
            new TestCases.LongestIncreasingSubsequence_300_Case(new int[]{0,1,0,3,2,3}, 4),
            new TestCases.LongestIncreasingSubsequence_300_Case(new int[]{7,7,7,7,7,7,7}, 1),
            new TestCases.LongestIncreasingSubsequence_300_Case(new int[]{3,10,2,1,20,4,6,21,22,23}, 6),
            new TestCases.LongestIncreasingSubsequence_300_Case(new int[]{9,2,5,3,7,101,18,9,4,5,6,7,8}, 7)
        );

        TestUtils.runCases(
            "LongestIncreasingSubsequence_300",
            cases,
            tc -> sol.lengthOfLIS(tc.nums()),
            TestCases.LongestIncreasingSubsequence_300_Case::expected
        );
    }

    public static void main(String[] args) {
        System.out.println("Running LeetCodeJava tests:\n");

        courseSchedule_207_tests();
        findIfPathExistsInGraph_1971_tests();
        numberOfIslands_200_tests();
        maxAreaOfIsland_695_tests();
        courseScheduleII_210_tests();
        networkDelayTime_743_tests();
        minCostToConnectAllPoints_1584_tests();
        longestIncreasingSubsequence_300_tests();
    }
}
