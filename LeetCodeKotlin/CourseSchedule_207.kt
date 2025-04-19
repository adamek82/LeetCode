class CourseSchedule_207 {
    private enum class Color { UNVISITED, VISITING, VISITED }

    fun canFinish(numCourses: Int, prerequisites: Array<IntArray>): Boolean {
        /* 1. build the graph */
        val graph = Array(numCourses) { mutableListOf<Int>() }
        for (p in prerequisites) graph[p[0]].add(p[1])      // edge: course -> prereq

        /* 2. colour array */
        val color = Array(numCourses) { Color.UNVISITED }

        /* 3. DFS */
        fun dfs(u: Int): Boolean {
            when (color[u]) {
                Color.VISITING -> return false              // back‑edge  ⇒ cycle
                Color.VISITED  -> return true               // already safe
                Color.UNVISITED -> {}                       // fall through
            }
            color[u] = Color.VISITING
            for (v in graph[u])
                if (!dfs(v)) return false
            color[u] = Color.VISITED
            return true
        }

        /* 4. explore every component */
        for (i in 0 until numCourses)
            if (!dfs(i)) return false
        return true
    }
}
