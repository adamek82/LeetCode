class CourseSchedule:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        graph = {i: [] for i in range(numCourses)}  # Create a graph
        for course, prereq in prerequisites:
            graph[course].append(prereq)
        
        # State tracking for each course: 0 = UNVISITED, 1 = VISITING, 2 = VISITED
        UNVISITED, VISITING, VISITED = 0, 1, 2
        states = [UNVISITED] * numCourses

        def dfs(course):
            if states[course] == VISITING:
                return False  # Cycle detected
            if states[course] == VISITED:
                return True  # Already visited
            
            # Mark the course as visiting
            states[course] = VISITING
            
            # Check all the neighbors (prerequisites)
            for prereq in graph[course]:
                if not dfs(prereq):
                    return False
            
            # Mark the course as fully visited
            states[course] = VISITED
            return True

        # Check if all courses can be finished
        for course in range(numCourses):
            if not dfs(course):
                return False
        return True
