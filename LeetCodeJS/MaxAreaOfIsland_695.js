/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    let maxArea = 0;

    function dfs(i, j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] !== 1) {
            return 0;
        }

        grid[i][j] = 0;  // Mark cell as visited
        let area = 1;    // Start with area of current cell

        // Explore all 4 directions
        area += dfs(i + 1, j);  // Down
        area += dfs(i - 1, j);  // Up
        area += dfs(i, j + 1);  // Right
        area += dfs(i, j - 1);  // Left

        return area;
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 1) {
                maxArea = Math.max(maxArea, dfs(i, j));
            }
        }
    }

    return maxArea;
};

module.exports = maxAreaOfIsland;