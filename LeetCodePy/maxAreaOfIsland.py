from typing import List

class MaxAreaOfIsland:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        rows, cols = len(grid), len(grid[0])

        def dfs(i: int, j: int) -> int:
            # Check for out-of-bounds or water cells
            if i < 0 or i >= rows or j < 0 or j >= cols or grid[i][j] != 1:
                return 0

            grid[i][j] = 0  # Mark cell as visited
            area = 1  # Start with area of the current cell

            # Explore all 4 directions
            area += dfs(i + 1, j)  # Down
            area += dfs(i - 1, j)  # Up
            area += dfs(i, j + 1)  # Right
            area += dfs(i, j - 1)  # Left

            return area

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    max_area = max(max_area, dfs(i, j))

        return max_area
