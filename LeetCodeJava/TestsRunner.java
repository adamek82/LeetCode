import java.util.HashMap;
import java.util.Map;
import java.util.function.BiFunction;

public class TestsRunner {

    // Method to test the CourseSchedule_207 task
    public static void courseSchedule_207_tests() {
        // Inner class for representing each test case
        class TestCase {
            int numCourses;
            int[][] prerequisites;
            boolean expectedResult;

            public TestCase(int numCourses, int[][] prerequisites, boolean expectedResult) {
                this.numCourses = numCourses;
                this.prerequisites = prerequisites;
                this.expectedResult = expectedResult;
            }
        }

        CourseSchedule_207 cs207 = new CourseSchedule_207();

        // Define test cases in an array
        TestCase[] testCases = {
            new TestCase(2, new int[][]{ {1, 0} }, true),
            new TestCase(2, new int[][]{ {1, 0}, {0, 1} }, false),
            new TestCase(5, new int[][]{ {0, 1}, {2, 3}, {3, 4}, {2, 1} }, true),
            new TestCase(5, new int[][]{ {0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2} }, false)
        };

        // Iterate through test cases
        for (int i = 0; i < testCases.length; i++) {
            boolean res = cs207.canFinish(testCases[i].numCourses, testCases[i].prerequisites);
            System.out.println("Test " + (i + 1) + ": res = " + (res == testCases[i].expectedResult ? "PASS" : "FAIL"));
        }
    }

    public static void findIfPathExistsInGraph_1971_tests() {
        // Inner class for representing each test case
        class TestCase {
            int n;
            int[][] edges;
            int source;
            int destination;
            boolean expectedResult;

            public TestCase(int n, int[][] edges, int source, int destination, boolean expectedResult) {
                this.n = n;
                this.edges = edges;
                this.source = source;
                this.destination = destination;
                this.expectedResult = expectedResult;
            }
        }

        FindIfPathExistsInGraph_1971 fp1971 = new FindIfPathExistsInGraph_1971();

        // Define test cases in an array
        TestCase[] testCases = {
            new TestCase(3, new int[][]{{0, 1}, {1, 2}, {2, 0}}, 0, 2, true),
            new TestCase(6, new int[][]{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false),
            new TestCase(4, new int[][]{{0, 1}, {1, 2}, {2, 3}}, 0, 3, true),
            new TestCase(5, new int[][]{{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true),
            new TestCase(4, new int[][]{{0, 1}, {1, 2}}, 0, 3, false)
        };

        // Iterate through test cases
        for (int i = 0; i < testCases.length; i++) {
            boolean res = fp1971.validPath(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            System.out.println("FindIfPathExistsInGraph Test " + (i + 1) + ": res = " + (res == testCases[i].expectedResult ? "PASS" : "FAIL"));
        }
    }

    public static void numIslandsTests() {
        class TestCase {
            char[][] grid;
            int expectedResult;

            public TestCase(char[][] grid, int expectedResult) {
                this.grid = grid;
                this.expectedResult = expectedResult;
            }
        }

        NumberOfIslands_200 solution = new NumberOfIslands_200();

        TestCase[] testCases = {
            new TestCase(new char[][]{
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}
            }, 1),

            new TestCase(new char[][]{
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
            }, 3),

            // Additional Test Case 1
            new TestCase(new char[][]{
                {'1', '0', '0', '0', '1'},
                {'0', '1', '1', '1', '0'},
                {'0', '1', '0', '1', '0'},
                {'1', '0', '0', '0', '1'}
            }, 5),

            // Additional Test Case 2
            new TestCase(new char[][]{
                {'1', '1', '1'},
                {'0', '1', '0'},
                {'1', '1', '1'}
            }, 1)
        };

        for (int i = 0; i < testCases.length; i++) {
            int res = solution.numIslands(testCases[i].grid);
            System.out.println("NumberOfIslands_200 Test " + (i + 1) + ": res = " + (res == testCases[i].expectedResult ? "PASS" : "FAIL") +
                    " (Expected: " + testCases[i].expectedResult + ", Got: " + res + ")");
        }
    }

    public static void maxAreaOfIslandTests() {
        class TestCase {
            int[][] grid;
            int expectedResult;

            public TestCase(int[][] grid, int expectedResult) {
                this.grid = grid;
                this.expectedResult = expectedResult;
            }
        }

        MaxAreaOfIsland_695 solution = new MaxAreaOfIsland_695();

        TestCase[] testCases = {
            new TestCase(new int[][]{
                {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
            }, 6), // Expected output: 6

            new TestCase(new int[][]{
                {0, 0, 0, 0, 0, 0, 0, 0}
            }, 0), // Expected output: 0

            // Additional Test Case 1
            new TestCase(new int[][]{
                {1, 1, 0, 0, 1, 1},
                {1, 0, 0, 0, 1, 1},
                {0, 0, 1, 1, 1, 0},
                {0, 0, 1, 0, 1, 1}
            }, 10), // Expected output: 10

            // Additional Test Case 2
            new TestCase(new int[][]{
                {0, 1, 1, 1},
                {1, 1, 0, 0},
                {1, 0, 0, 1},
                {1, 1, 1, 0}
            }, 9) // Expected output: 9
        };

        for (int i = 0; i < testCases.length; i++) {
            int res = solution.maxAreaOfIsland(testCases[i].grid);
            System.out.println("MaxAreaOfIsland_695 Test " + (i + 1) + ": res = " + (res == testCases[i].expectedResult ? "PASS" : "FAIL") +
                    " (Expected: " + testCases[i].expectedResult + ", Got: " + res + ")");
        }
    }

    public static void courseScheduleII_210_tests() {
        // Inner class for representing each test case
        class TestCase {
            int numCourses;
            int[][] prerequisites;
            int[] expectedOrder;  // Empty array indicates a cycle, so order is invalid

            public TestCase(int numCourses, int[][] prerequisites, int[] expectedOrder) {
                this.numCourses = numCourses;
                this.prerequisites = prerequisites;
                this.expectedOrder = expectedOrder;
            }
        }

        CourseScheduleII_210 cs210 = new CourseScheduleII_210();

        // Define test cases in an array
        TestCase[] testCases = {
            new TestCase(2, new int[][]{{1, 0}}, new int[]{0, 1}),
            new TestCase(4, new int[][]{{1, 0}, {2, 0}, {3, 1}, {3, 2}}, new int[]{0, 1, 2, 3}),
            new TestCase(1, new int[][]{}, new int[]{0}),
            new TestCase(6, new int[][]{{1, 0}, {2, 0}, {3, 4}, {5, 4}}, new int[]{0, 1, 2, 4, 3, 5}),
            new TestCase(5, new int[][]{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}, new int[]{})
        };

        // Lambda function for validating the order
        BiFunction<int[], TestCase, Boolean> isValidOrder = (order, testCase) -> {
            if (testCase.expectedOrder.length == 0) {
                return order.length == 0;  // Expect empty result if there was a cycle
            }

            Map<Integer, Integer> position = new HashMap<>();
            for (int i = 0; i < order.length; i++) {
                position.put(order[i], i);
            }

            for (int[] prereq : testCase.prerequisites) {
                int course = prereq[0], prerequisite = prereq[1];
                if (position.getOrDefault(prerequisite, -1) > position.getOrDefault(course, -1)) {
                    return false;  // Prerequisite appears after the course, invalid order
                }
            }

            return true;  // All prerequisites are satisfied in the order
        };

        for (int i = 0; i < testCases.length; i++) {
            int[] result = cs210.findOrder(testCases[i].numCourses, testCases[i].prerequisites);
            boolean pass = isValidOrder.apply(result, testCases[i]);
            System.out.println("Test " + (i + 1) + ": res = " + (pass ? "PASS" : "FAIL"));
        }
    }

    public static void networkDelayTime_743_tests() {
        // Inner class for representing each test case
        class TestCase {
            int[][] times; // Edge list
            int n;         // Number of nodes
            int k;         // Starting node
            int expectedResult;

            public TestCase(int[][] times, int n, int k, int expectedResult) {
                this.times = times;
                this.n = n;
                this.k = k;
                this.expectedResult = expectedResult;
            }
        }

        NetworkDelayTime_743 solution = new NetworkDelayTime_743();

        // Define test cases in an array
        TestCase[] testCases = {
            // Provided Examples
            new TestCase(new int[][]{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2, 2),
            new TestCase(new int[][]{{1, 2, 1}}, 2, 1, 1),
            new TestCase(new int[][]{{1, 2, 1}}, 2, 2, -1),

            // Additional Complex Example 1
            new TestCase(new int[][]{{1, 2, 2}, {1, 3, 4}, {2, 4, 7}, {3, 4, 1}, {2, 5, 5}, {5, 6, 3}, {4, 6, 2}}, 6, 1, 7),

            // Additional Complex Example 2
            new TestCase(new int[][]{{1, 2, 2}, {1, 3, 1}, {3, 4, 4}, {2, 5, 7}, {5, 6, 1}, {6, 7, 5}, {7, 8, 2}, {4, 8, 3}}, 8, 1, 15)
        };

        // Iterate through test cases
        for (int i = 0; i < testCases.length; i++) {
            int result = solution.networkDelayTime(testCases[i].times, testCases[i].n, testCases[i].k);
            System.out.println("NetworkDelayTime_743 Test " + (i + 1) + ": res = " +
                (result == testCases[i].expectedResult ? "PASS" : "FAIL") +
                " (Expected: " + testCases[i].expectedResult + ", Got: " + result + ")");
        }
    }

    public static void minCostToConnectAllPoints_1584_tests() {
        class TestCase {
            int[][] points;
            int expectedResult;
    
            public TestCase(int[][] points, int expectedResult) {
                this.points = points;
                this.expectedResult = expectedResult;
            }
        }
    
        MinCostToConnectAllPoints_1584 solution = new MinCostToConnectAllPoints_1584();
    
        TestCase[] testCases = {
            // Provided examples
            new TestCase(new int[][]{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}}, 20),
            new TestCase(new int[][]{{3, 12}, {-2, 5}, {-4, 1}}, 18),
    
            // Additional complex examples
            new TestCase(new int[][]{{1, 1}, {3, 3}, {7, 7}, {10, 10}, {15, 15}}, 28), // Sequential points
            new TestCase(new int[][]{{0, 0}, {1, 1}, {1, 0}, {0, 1}, {2, 2}}, 5),     // Compact grid
            new TestCase(new int[][]{{-100, -100}, {100, 100}, {-100, 100}, {100, -100}}, 600) // Distant points
        };
    
        for (int i = 0; i < testCases.length; i++) {
            int result = solution.minCostConnectPoints(testCases[i].points);
            System.out.println("MinCostToConnectAllPoints_1584 Test " + (i + 1) + ": res = " +
                (result == testCases[i].expectedResult ? "PASS" : "FAIL") +
                " (Expected: " + testCases[i].expectedResult + ", Got: " + result + ")");
        }
    }

    public static void main(String[] args) {
        System.out.println("Running LeetCodeJava tests:");

        System.out.println("Running CourseSchedule_207 tests:");
        courseSchedule_207_tests();

        System.out.println("\nRunning FindIfPathExistsInGraph_1971 tests:");
        findIfPathExistsInGraph_1971_tests();

        System.out.println("\nRunning NumberOfIslands_200 tests:");
        numIslandsTests();

        System.out.println("Running MaxAreaOfIsland_695 tests:");
        maxAreaOfIslandTests();

        System.out.println("Running CourseScheduleII_210 tests:");
        courseScheduleII_210_tests();

        System.out.println("\nRunning NetworkDelayTime_743 tests:");
        networkDelayTime_743_tests();

        System.out.println("\nRunning MinCostToConnectAllPoints_1584 tests:");
        minCostToConnectAllPoints_1584_tests();
    }
}