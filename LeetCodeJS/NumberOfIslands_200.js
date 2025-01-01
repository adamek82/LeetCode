/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let numIslands = 0;

    const dfs = (i, j) => {
        // Check bounds and if the cell is '0' (water or visited land).
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] !== '1') {
            return;
        }

        // Mark the current cell as visited by setting it to '0'.
        grid[i][j] = '0';

        // Visit all four adjacent cells.
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    };

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '1') {
                numIslands++;
                dfs(i, j);
            }
        }
    }

    return numIslands;
};

module.exports = numIslands;
