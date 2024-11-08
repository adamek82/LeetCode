from CourseSchedule import CourseSchedule
from FindIfPathExistsInGraph_1971 import FindIfPathExistsInGraph_1971
from NumberOfIslands_200 import NumberOfIslands_200
from maxAreaOfIsland import MaxAreaOfIsland
from CourseScheduleII_210 import CourseScheduleII_210

# Class to represent each test case
class CourseScheduleTestCase:
    def __init__(self, numCourses, prerequisites, expectedResult):
        self.numCourses = numCourses
        self.prerequisites = prerequisites
        self.expectedResult = expectedResult

def course_schedule_tests():
    cs = CourseSchedule()

    # Define test cases in an array
    test_cases = [
        CourseScheduleTestCase(2, [[1, 0]], True),
        CourseScheduleTestCase(2, [[1, 0], [0, 1]], False),
        CourseScheduleTestCase(5, [[0, 1], [2, 3], [3, 4], [2, 1]], True),
        CourseScheduleTestCase(5, [[0, 1], [2, 3], [3, 4], [2, 1], [4, 2]], False)
    ]

    # Iterate through test cases
    for i, test in enumerate(test_cases):
        res = cs.canFinish(test.numCourses, test.prerequisites)
        print(f"Test {i + 1}: res = {'PASS' if res == test.expectedResult else 'FAIL'}")

# Class to represent each test case
class PathTestCase:
    def __init__(self, n, edges, source, destination, expectedResult):
        self.n = n
        self.edges = edges
        self.source = source
        self.destination = destination
        self.expectedResult = expectedResult

def find_if_path_exists_tests():
    fp = FindIfPathExistsInGraph_1971()

    # Define test cases
    test_cases = [
        PathTestCase(3, [[0, 1], [1, 2], [2, 0]], 0, 2, True),
        PathTestCase(6, [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]], 0, 5, False),
        PathTestCase(4, [[0, 1], [1, 2], [2, 3]], 0, 3, True),
        PathTestCase(5, [[0, 4], [4, 3], [3, 2], [2, 1]], 0, 1, True),
        PathTestCase(4, [[0, 1], [1, 2]], 0, 3, False)
    ]

    # Run each test case
    for i, test in enumerate(test_cases):
        res = fp.validPath(test.n, test.edges, test.source, test.destination)
        print(f"FindIfPathExistsInGraph Test {i + 1}: res = {'PASS' if res == test.expectedResult else 'FAIL'}")

class NumIslandsTestCase:
    def __init__(self, grid, expectedResult):
        self.grid = grid
        self.expectedResult = expectedResult

def num_islands_tests():
    solution = NumberOfIslands_200()

    test_cases = [
        NumIslandsTestCase([
            ['1', '1', '1', '1', '0'],
            ['1', '1', '0', '1', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '0', '0', '0']
        ], 1),

        NumIslandsTestCase([
            ['1', '1', '0', '0', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '1', '0', '0'],
            ['0', '0', '0', '1', '1']
        ], 3),

        # Additional Test Case 1
        NumIslandsTestCase([
            ['1', '0', '0', '0', '1'],
            ['0', '1', '1', '1', '0'],
            ['0', '1', '0', '1', '0'],
            ['1', '0', '0', '0', '1']
        ], 5),

        # Additional Test Case 2
        NumIslandsTestCase([
            ['1', '1', '1'],
            ['0', '1', '0'],
            ['1', '1', '1']
        ], 1)
    ]

    for i, test in enumerate(test_cases):
        # Deep copy the grid for testing to avoid modifying the original
        grid_copy = [row[:] for row in test.grid]
        result = solution.numIslands(grid_copy)
        print(f"NumberOfIslands_200 Test {i + 1}: res = {'PASS' if result == test.expectedResult else 'FAIL'} "
              f"(Expected: {test.expectedResult}, Got: {result})")

class MaxAreaTestCase:
    def __init__(self, grid, expected_result):
        self.grid = grid
        self.expected_result = expected_result

def max_area_of_island_tests():
    solution = MaxAreaOfIsland()

    test_cases = [
        MaxAreaTestCase([
            [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
            [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
            [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
        ], 6),  # Expected output: 6

        MaxAreaTestCase([
            [0, 0, 0, 0, 0, 0, 0, 0]
        ], 0),  # Expected output: 0

        # Additional Test Case 1
        MaxAreaTestCase([
            [1, 1, 0, 0, 1, 1],
            [1, 0, 0, 0, 1, 1],
            [0, 0, 1, 1, 1, 0],
            [0, 0, 1, 0, 1, 1]
        ], 10),  # Expected output: 10

        # Additional Test Case 2
        MaxAreaTestCase([
            [0, 1, 1, 1],
            [1, 1, 0, 0],
            [1, 0, 0, 1],
            [1, 1, 1, 0]
        ], 9)  # Expected output: 9
    ]

    for i, test in enumerate(test_cases):
        # Deep copy the grid for testing to avoid modifying the original
        grid_copy = [row[:] for row in test.grid]
        result = solution.maxAreaOfIsland(grid_copy)
        print(f"MaxAreaOfIsland_695 Test {i + 1}: res = {'PASS' if result == test.expected_result else 'FAIL'} "
              f"(Expected: {test.expected_result}, Got: {result})")

def course_schedule_ii_tests():
    cs210 = CourseScheduleII_210()

    test_cases = [
        CourseScheduleTestCase(2, [[1, 0]], [0, 1]),
        CourseScheduleTestCase(4, [[1, 0], [2, 0], [3, 1], [3, 2]], [0, 1, 2, 3]),
        CourseScheduleTestCase(1, [], [0]),
        CourseScheduleTestCase(6, [[1, 0], [2, 0], [3, 4], [5, 4]], [0, 1, 2, 4, 3, 5]),
        CourseScheduleTestCase(5, [[0, 1], [1, 2], [2, 3], [3, 4], [4, 0]], [])
    ]

    def is_valid_order(order, numCourses, prerequisites):
        position = {course: i for i, course in enumerate(order)}
        for course, prerequisite in prerequisites:
            if position.get(prerequisite, -1) > position.get(course, -1):
                return False  # Invalid if prerequisite appears after the course
        return True

    for i, test in enumerate(test_cases):
        result = cs210.findOrder(test.numCourses, test.prerequisites)
        is_valid = (len(test.expectedResult) == 0 and len(result) == 0) or \
                   (len(test.expectedResult) > 0 and is_valid_order(result, test.numCourses, test.prerequisites))
        print(f"Course Schedule II Test {i + 1}: res = {'PASS' if is_valid else 'FAIL'}")

if __name__ == "__main__":
    course_schedule_tests()
    find_if_path_exists_tests()
    num_islands_tests()
    max_area_of_island_tests()
    course_schedule_ii_tests()
