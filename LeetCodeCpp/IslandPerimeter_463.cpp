#include "IslandPerimeter_463.h"

/*
 * Approach
 * --------
 * We scan the grid and treat every land cell as an isolated 1x1 square at first.
 * Each such square contributes 4 edges to the perimeter:
 *
 *     [#]  →  4 edges
 *
 * However, whenever two land cells are adjacent (share a side), the edge between
 * them is not part of the *outer* perimeter anymore. That shared edge is counted
 * twice if we naïvely do "+4 per land cell":
 *   - once as the right edge of the left cell,
 *   - once as the left edge of the right cell (for a horizontal pair),
 *   - similarly for vertical pairs (bottom of one, top of the other).
 *
 * Example (two horizontal land cells):
 *
 *     grid: [#][#]
 *
 * Naïve counting:
 *   - left cell  : 4 edges
 *   - right cell : 4 edges
 *   total        : 8
 *
 * But the true perimeter of the combined shape is:
 *
 *     +----+----+
 *     | ## | ## |
 *     +----+----+
 *
 * If we count only the *outer* edges:
 *   - top side      → 2 edge segments
 *   - bottom side   → 2 edge segments
 *   - left border   → 1 edge segment
 *   - right border  → 1 edge segment
 *   total           → 6 edge segments
 *
 * The vertical edge between the two cells is internal. It was counted twice
 * in the naïve sum (once as the right edge of the left cell and once as the
 * left edge of the right cell), but it should not contribute to the island
 * perimeter at all. Therefore, for each *pair* of adjacent land cells, we must
 * subtract 2 from the running total.
 *
 * To avoid double-counting the same shared edge, we only look "backwards":
 *   - the top neighbor (r - 1, c)
 *   - the left neighbor (r, c - 1)
 *
 * When the current cell (r, c) is land:
 *   - perimeter += 4               // assume it is isolated
 *   - if top neighbor is land  → perimeter -= 2 (shared vertical edge)
 *   - if left neighbor is land → perimeter -= 2 (shared horizontal edge)
 *
 * This way, every shared edge between two adjacent land cells is processed
 * exactly once, and we subtract 2 exactly once for that pair, correcting the
 * over-counting and yielding the correct final perimeter.
 */
int IslandPerimeter_463::islandPerimeter(const vector<vector<int>>& grid) {
    const int rows = static_cast<int>(grid.size());
    if (rows == 0) return 0;
    const int cols = static_cast<int>(grid[0].size());

    int perimeter = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 0) continue;

            // Each land cell contributes 4 sides…
            perimeter += 4;

            // …minus 2 for each shared edge with an already-seen neighbor
            if (r > 0 && grid[r - 1][c] == 1) perimeter -= 2; // top neighbor
            if (c > 0 && grid[r][c - 1] == 1) perimeter -= 2; // left neighbor
        }
    }

    return perimeter;
}
