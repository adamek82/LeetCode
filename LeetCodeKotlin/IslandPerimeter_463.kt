class IslandPerimeter_463 {
    fun islandPerimeter(grid: Array<IntArray>): Int {
        val directions = arrayOf(
            intArrayOf(0, 1),
            intArrayOf(1, 0),
            intArrayOf(0, -1),
            intArrayOf(-1, 0)
        )
        var perimeter = 0

        for (i in grid.indices) {
            for (j in grid[i].indices) {
                if (grid[i][j] == 1) {
                    // Start with 4 edges
                    perimeter += 4

                    // Subtract 1 for every adjacent land cell
                    for ((dx, dy) in directions) {
                        val x = i + dx
                        val y = j + dy
                        if (x in grid.indices && y in grid[x].indices && grid[x][y] == 1) {
                            perimeter--
                        }
                    }
                }
            }
        }

        return perimeter
    }
}