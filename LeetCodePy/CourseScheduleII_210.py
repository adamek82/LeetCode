from typing import List
from collections import defaultdict

class CourseScheduleII_210:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        order = []
        graph = defaultdict(list)
        
        for course, pre in prerequisites:
            graph[course].append(pre)
        
        UNVISITED, VISITING, VISITED = 0, 1, 2
        states = [UNVISITED] * numCourses

        def dfs(course: int) -> bool:
            if states[course] == VISITING:
                return False  # Cycle detected
            if states[course] == VISITED:
                return True  # Already processed
            
            states[course] = VISITING
            for neighbor in graph[course]:
                if not dfs(neighbor):
                    return False
            
            states[course] = VISITED
            order.append(course)  # Append directly to order
            return True

        for i in range(numCourses):
            if states[i] == UNVISITED:
                if not dfs(i):
                    return []  # Return empty list if a cycle is detected

        return order
