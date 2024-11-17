const CourseSchedule_207 = require('./CourseSchedule_207');
const FindIfPathExistsInGraph_1971 = require('./FindIfPathExistsInGraph_1971');
const numberOfIslands_200 = require('./NumberOfIslands_200');
const maxAreaOfIsland_695 = require('./maxAreaOfIsland_695');
const CourseScheduleII_210 = require('./CourseScheduleII_210');
const networkDelayTime_743 = require('./NetworkDelayTime_743');

// Test case structure for course schedule
class TestCase {
    constructor(numCourses, prerequisites, expectedResult) {
        this.numCourses = numCourses;
        this.prerequisites = prerequisites;
        this.expectedResult = expectedResult;
    }
}

// Test case structure for path existence
class PathTestCase {
    constructor(n, edges, source, destination, expectedResult) {
        this.n = n;
        this.edges = edges;
        this.source = source;
        this.destination = destination;
        this.expectedResult = expectedResult;
    }
}

// Test case structure for numIslands
class NumIslandsTestCase {
    constructor(grid, expectedResult) {
        this.grid = grid;
        this.expectedResult = expectedResult;
    }
}

class MaxAreaTestCase {
    constructor(grid, expectedResult) {
        this.grid = grid;
        this.expectedResult = expectedResult;
    }
}

// Test runner
class TestsRunner {
    static courseScheduleTests() {
        const testCases = [
            new TestCase(2, [[1, 0]], true),
            new TestCase(2, [[1, 0], [0, 1]], false),
            new TestCase(5, [[0, 1], [2, 3], [3, 4], [2, 1]], true),
            new TestCase(5, [[0, 1], [2, 3], [3, 4], [2, 1], [4, 2]], false)
        ];

        const courseSchedule = new CourseSchedule_207();

        testCases.forEach((testCase, index) => {
            const result = courseSchedule.canFinish(testCase.numCourses, testCase.prerequisites);
            console.log(`Course Schedule Test ${index + 1}: res = ${result === testCase.expectedResult ? 'PASS' : 'FAIL'}`);
        });
    }

    static findIfPathExistsTests() {
        const testCases = [
            new PathTestCase(3, [[0, 1], [1, 2], [2, 0]], 0, 2, true),
            new PathTestCase(6, [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]], 0, 5, false),
            new PathTestCase(4, [[0, 1], [1, 2], [2, 3]], 0, 3, true),
            new PathTestCase(5, [[0, 4], [4, 3], [3, 2], [2, 1]], 0, 1, true),
            new PathTestCase(4, [[0, 1], [1, 2]], 0, 3, false)
        ];

        const findIfPathExists = new FindIfPathExistsInGraph_1971();

        testCases.forEach((testCase, index) => {
            const result = findIfPathExists.validPath(testCase.n, testCase.edges, testCase.source, testCase.destination);
            console.log(`Find If Path Exists Test ${index + 1}: res = ${result === testCase.expectedResult ? 'PASS' : 'FAIL'}`);
        });
    }

    static numIslandsTests() {
        const testCases = [
            new NumIslandsTestCase(
                [
                    ['1', '1', '1', '1', '0'],
                    ['1', '1', '0', '1', '0'],
                    ['1', '1', '0', '0', '0'],
                    ['0', '0', '0', '0', '0']
                ], 1
            ),
            new NumIslandsTestCase(
                [
                    ['1', '1', '0', '0', '0'],
                    ['1', '1', '0', '0', '0'],
                    ['0', '0', '1', '0', '0'],
                    ['0', '0', '0', '1', '1']
                ], 3
            ),
            // Additional Test Case 1
            new NumIslandsTestCase(
                [
                    ['1', '0', '0', '0', '1'],
                    ['0', '1', '1', '1', '0'],
                    ['0', '1', '0', '1', '0'],
                    ['1', '0', '0', '0', '1']
                ], 5
            ),
            // Additional Test Case 2
            new NumIslandsTestCase(
                [
                    ['1', '1', '1'],
                    ['0', '1', '0'],
                    ['1', '1', '1']
                ], 1
            )
        ];

        testCases.forEach((testCase, index) => {
            const result = numberOfIslands_200(testCase.grid.map(row => [...row])); // Copy each row to avoid modifying original
            console.log(`Num Islands Test ${index + 1}: res = ${result === testCase.expectedResult ? 'PASS' : 'FAIL'} `
                        + `(Expected: ${testCase.expectedResult}, Got: ${result})`);
        });
    }

    static maxAreaOfIslandTests() {
        const testCases = [
            new MaxAreaTestCase(
                [
                    [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                    [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
                    [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
                ], 6
            ),

            new MaxAreaTestCase(
                [
                    [0, 0, 0, 0, 0, 0, 0, 0]
                ], 0
            ),

            // Additional Test Case 1
            new MaxAreaTestCase(
                [
                    [1, 1, 0, 0, 1, 1],
                    [1, 0, 0, 0, 1, 1],
                    [0, 0, 1, 1, 1, 0],
                    [0, 0, 1, 0, 1, 1]
                ], 10
            ),

            // Additional Test Case 2
            new MaxAreaTestCase(
                [
                    [0, 1, 1, 1],
                    [1, 1, 0, 0],
                    [1, 0, 0, 1],
                    [1, 1, 1, 0]
                ], 9
            )
        ];

        testCases.forEach((testCase, index) => {
            const result = maxAreaOfIsland_695(testCase.grid.map(row => [...row]));  // Copy each row to avoid modifying original
            console.log(`Max Area of Island Test ${index + 1}: res = ${result === testCase.expectedResult ? 'PASS' : 'FAIL'} `
                        + `(Expected: ${testCase.expectedResult}, Got: ${result})`);
        });
    }

    static courseScheduleIITests() {
        const testCases = [
            new TestCase(2, [[1, 0]], [0, 1]),
            new TestCase(4, [[1, 0], [2, 0], [3, 1], [3, 2]], [0, 1, 2, 3]),
            new TestCase(1, [], [0]),
            new TestCase(6, [[1, 0], [2, 0], [3, 4], [5, 4]], [0, 1, 2, 4, 3, 5]),
            new TestCase(5, [[0, 1], [1, 2], [2, 3], [3, 4], [4, 0]], [])
        ];

        const courseScheduleII = new CourseScheduleII_210();

        // Local helper function to validate course order
        const isValidOrder = (order, numCourses, prerequisites) => {
            const position = new Map();
            order.forEach((course, index) => position.set(course, index));

            for (const [course, prerequisite] of prerequisites) {
                if (position.get(prerequisite) > position.get(course)) {
                    return false; // If prerequisite appears after course, order is invalid
                }
            }

            return true; // All prerequisites are satisfied in the given order
        };

        testCases.forEach((testCase, index) => {
            const result = courseScheduleII.findOrder(testCase.numCourses, testCase.prerequisites);

            const isValid = testCase.expectedResult.length === 0
                ? result.length === 0
                : isValidOrder(result, testCase.numCourses, testCase.prerequisites);

            console.log(`Course Schedule II Test ${index + 1}: res = ${isValid ? 'PASS' : 'FAIL'}`);
        });
    }

    static networkDelayTimeTests() {
        class TestCase {
            constructor(times, n, k, expectedResult) {
                this.times = times;
                this.n = n;
                this.k = k;
                this.expectedResult = expectedResult;
            }
        }

        const testCases = [
            // Provided Examples
            new TestCase([[2, 1, 1], [2, 3, 1], [3, 4, 1]], 4, 2, 2),
            new TestCase([[1, 2, 1]], 2, 1, 1),
            new TestCase([[1, 2, 1]], 2, 2, -1),

            // Additional Complex Example 1: 6 nodes, complex network
            new TestCase([[1, 2, 2], [1, 3, 4], [2, 4, 7], [3, 4, 1], [2, 5, 5], [5, 6, 3], [4, 6, 2]], 6, 1, 7),

            // Additional Complex Example 2: 8 nodes, complex network
            new TestCase([[1, 2, 2], [1, 3, 1], [3, 4, 4], [2, 5, 7], [5, 6, 1], [6, 7, 5], [7, 8, 2], [4, 8, 3]], 8, 1, 15),
        ];

        testCases.forEach((testCase, index) => {
            const result = networkDelayTime_743(testCase.times, testCase.n, testCase.k);
            const isValid = result === testCase.expectedResult;

            console.log(`Network Delay Time Test ${index + 1}: res = ${isValid ? 'PASS' : 'FAIL'} (Expected: ${testCase.expectedResult}, Got: ${result})`);
        });
    }

    static runAllTests() {
        console.log("Running LeetCodeJS tests:");

        console.log("Running Course Schedule tests:");
        this.courseScheduleTests();

        console.log("\nRunning Find If Path Exists tests:");
        this.findIfPathExistsTests();

        console.log("\nRunning Number of Islands tests:");
        this.numIslandsTests();

        console.log("\nRunning Max Area of Island tests:");
        this.maxAreaOfIslandTests();

        console.log("\nRunning Course Schedule II tests:");
        this.courseScheduleIITests();

        console.log("Running Network Delay Time Tests:");
        this.networkDelayTimeTests();
    }
}

// Run the tests
TestsRunner.runAllTests();
