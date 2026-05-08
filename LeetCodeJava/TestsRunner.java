import java.util.List;

public class TestsRunner {

    // =========================================================================
    // Hashmaps & Sets
    // =========================================================================

    /* More advanced set/map usage for ordering and sequence reasoning */

    private static void longestConsecutiveSequence_128_tests() {
        LongestConsecutiveSequence_128 sol = new LongestConsecutiveSequence_128();

        var cases = List.of(
            // Examples from problem statement
            new TestCases.LongestConsecutiveSequence_128_Case(new int[]{100,4,200,1,3,2}, 4),
            new TestCases.LongestConsecutiveSequence_128_Case(new int[]{0,3,7,2,5,8,4,6,0,1}, 9),
            new TestCases.LongestConsecutiveSequence_128_Case(new int[]{1,0,1,2}, 3),

            // Additional complex cases
            new TestCases.LongestConsecutiveSequence_128_Case(new int[]{-1,-2,-3,7,6,5,4,3,2,1}, 7),
            new TestCases.LongestConsecutiveSequence_128_Case(new int[]{10,5,12,3,55,30,4,11,11,5,13,14,6}, 5),

            // Boundary values guarding against integer overflow in x - 1 / end + 1
            new TestCases.LongestConsecutiveSequence_128_Case(
                new int[]{Integer.MAX_VALUE - 1, Integer.MAX_VALUE},
                2
            ),
            new TestCases.LongestConsecutiveSequence_128_Case(
                new int[]{Integer.MIN_VALUE, Integer.MIN_VALUE + 1},
                2
            )
        );

        TestUtils.runCases(
            "LongestConsecutiveSequence_128",
            cases,
            tc -> sol.longestConsecutive(tc.nums()),
            TestCases.LongestConsecutiveSequence_128_Case::expected
        );
    }

    // =========================================================================
    // 2 Pointers
    // =========================================================================

    /* Shrinking-window reasoning with left/right boundaries */

    private static void trappingRainWater_42_tests() {
        TrappingRainWater_42 sol = new TrappingRainWater_42();

        var cases = List.of(
            new TestCases.TrappingRainWater_42_Case(new int[]{0,1,0,2,1,0,1,3,2,1,2,1}, 6),
            new TestCases.TrappingRainWater_42_Case(new int[]{4,2,0,3,2,5}, 9),
            new TestCases.TrappingRainWater_42_Case(new int[]{0,0,0}, 0),
            new TestCases.TrappingRainWater_42_Case(new int[]{1,2,3,4,5}, 0),
            new TestCases.TrappingRainWater_42_Case(new int[]{5,4,1,2}, 1),
            new TestCases.TrappingRainWater_42_Case(new int[]{4,0,0,0,4}, 12)
        );

        TestUtils.runCases(
            "TrappingRainWater_42",
            cases,
            tc -> sol.trap(tc.height()),
            TestCases.TrappingRainWater_42_Case::expected
        );
    }

    // =========================================================================
    // Recursive Backtracking
    // =========================================================================

    /* Backtracking over a 2D search space with visited-state control */

    private static void wordSearch_79_tests() {
        WordSearch_79 sol = new WordSearch_79();

        var cases = List.of(
            // Example 1 from problem statement
            new TestCases.WordSearch_79_Case(new char[][]{
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
            }, "ABCCED", true),

            // Example 2 from problem statement
            new TestCases.WordSearch_79_Case(new char[][]{
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
            }, "SEE", true),

            // Example 3 from problem statement
            new TestCases.WordSearch_79_Case(new char[][]{
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
            }, "ABCB", false),

            // Additional complex test case 1
            new TestCases.WordSearch_79_Case(new char[][]{
                {'A', 'B', 'C', 'E', 'F', 'G'},
                {'H', 'I', 'J', 'K', 'L', 'M'},
                {'N', 'O', 'P', 'Q', 'R', 'S'},
                {'T', 'U', 'V', 'W', 'X', 'Y'},
                {'Z', 'A', 'B', 'C', 'D', 'E'}
            }, "ABCEFGMLKJIHNT", true),

            // Additional complex test case 2
            new TestCases.WordSearch_79_Case(new char[][]{
                {'A', 'B', 'C', 'E', 'F', 'G'},
                {'H', 'I', 'J', 'K', 'L', 'M'},
                {'N', 'O', 'P', 'Q', 'R', 'S'},
                {'T', 'U', 'V', 'W', 'X', 'Y'},
                {'Z', 'A', 'B', 'C', 'D', 'E'}
            }, "ZYXWVUTSRQPONMLK", false)
        );

        TestUtils.runCases(
            "WordSearch_79",
            cases,
            tc -> sol.exist(GridUtils.copy(tc.board()), tc.word()),
            TestCases.WordSearch_79_Case::expected
        );
    }

    // =========================================================================
    // Graphs
    // =========================================================================

    // Basic graph / grid traversal for reachability and connected components

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

    // Directed-graph reasoning with topological order and cycle detection

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

    private static void courseScheduleII_210_tests() {
        CourseScheduleII_210 sol = new CourseScheduleII_210();

        var cases = List.of(
            new TestCases.CourseScheduleII_210_Case(2, new int[][]{{1, 0}}, new int[]{0, 1}),
            new TestCases.CourseScheduleII_210_Case(4, new int[][]{{1, 0}, {2, 0}, {3, 1}, {3, 2}}, new int[]{0, 1, 2, 3}),
            new TestCases.CourseScheduleII_210_Case(1, new int[][]{}, new int[]{0}),
            new TestCases.CourseScheduleII_210_Case(6, new int[][]{{1, 0}, {2, 0}, {3, 4}, {5, 4}}, new int[]{0, 1, 2, 4, 3, 5}),
            new TestCases.CourseScheduleII_210_Case(5, new int[][]{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}, new int[]{})
        );

        TestUtils.runCases(
            "CourseScheduleII_210",
            cases,
            tc -> sol.findOrder(tc.numCourses(), tc.prerequisites()),
            (tc, got) -> tc.expectCycle()
                ? (got != null && got.length == 0)
                : TestCases.isValidTopologicalOrder(got, tc.numCourses(), tc.prerequisites()),
            tc -> tc.expectCycle() ? "[]" : "any valid topological order",
            TestUtils::fmt
        );
    }

    // Weighted graph algorithms: shortest paths and minimum spanning tree

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

    // =========================================================================
    // Dynamic Programming
    // =========================================================================

    // Sequence DP on increasing structure and string matching

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
            "LongestIncreasingSubsequence_300 - custom lower_bound",
            cases,
            tc -> sol.lengthOfLIS_customLowerBound(tc.nums()),
            TestCases.LongestIncreasingSubsequence_300_Case::expected
        );

        TestUtils.runCases(
            "LongestIncreasingSubsequence_300 - Arrays.binarySearch",
            cases,
            tc -> sol.lengthOfLIS_arraysBinarySearch(tc.nums()),
            TestCases.LongestIncreasingSubsequence_300_Case::expected
        );
    }

    public static void main(String[] args) {
        System.out.println("Running LeetCodeJava tests:\n");

        // =========================================================================
        // Hashmaps & Sets
        // =========================================================================

        /* More advanced set/map usage for ordering and sequence reasoning */
        longestConsecutiveSequence_128_tests();

        // =========================================================================
        // 2 Pointers
        // =========================================================================

        /* Shrinking-window reasoning with left/right boundaries */
        trappingRainWater_42_tests();

        // =========================================================================
        // Recursive Backtracking
        // =========================================================================

        /* Backtracking over a 2D search space with visited-state control */
        wordSearch_79_tests();

        // =========================================================================
        // Graphs
        // =========================================================================

        // Basic graph / grid traversal for reachability and connected components
        findIfPathExistsInGraph_1971_tests();
        numberOfIslands_200_tests();
        maxAreaOfIsland_695_tests();

        // Directed-graph reasoning with topological order and cycle detection
        courseSchedule_207_tests();
        courseScheduleII_210_tests();

        // Weighted graph algorithms: shortest paths and minimum spanning tree
        networkDelayTime_743_tests();
        minCostToConnectAllPoints_1584_tests();

        // =========================================================================
        // Dynamic Programming
        // =========================================================================

        // Sequence DP on increasing structure and string matching
        longestIncreasingSubsequence_300_tests();
    }
}
