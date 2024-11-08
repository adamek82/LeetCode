// courseSchedule.js
class CourseSchedule {
    static UNVISITED = 0;
    static VISITING = 1;
    static VISITED = 2;

    canFinish(numCourses, prerequisites) {
        const graph = new Map();

        // Build the graph
        prerequisites.forEach(([course, prereq]) => {
            if (!graph.has(course)) {
                graph.set(course, []);
            }
            graph.get(course).push(prereq);
        });

        const states = Array(numCourses).fill(CourseSchedule.UNVISITED);

        const dfs = (course) => {
            if (states[course] === CourseSchedule.VISITING) return false; // Cycle detected
            if (states[course] === CourseSchedule.VISITED) return true;   // Already visited

            states[course] = CourseSchedule.VISITING;
            const neighbors = graph.get(course) || [];

            for (let neighbor of neighbors) {
                if (!dfs(neighbor)) {
                    return false;
                }
            }

            states[course] = CourseSchedule.VISITED;
            return true;
        };

        for (let i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }

        return true;
    }
}

// Export the CourseSchedule class
module.exports = CourseSchedule;
