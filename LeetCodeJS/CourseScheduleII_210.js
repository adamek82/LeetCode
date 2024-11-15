// courseScheduleII.js
class CourseScheduleII_210 {
    static UNVISITED = 0;
    static VISITING = 1;
    static VISITED = 2;

    findOrder(numCourses, prerequisites) {
        const order = [];
        const graph = new Map();

        // Build the graph
        prerequisites.forEach(([course, prereq]) => {
            if (!graph.has(course)) {
                graph.set(course, []);
            }
            graph.get(course).push(prereq);
        });

        const states = Array(numCourses).fill(CourseScheduleII_210.UNVISITED);

        const dfs = (course) => {
            if (states[course] === CourseScheduleII_210.VISITING) return false; // Cycle detected
            if (states[course] === CourseScheduleII_210.VISITED) return true;    // Already processed

            states[course] = CourseScheduleII_210.VISITING;
            const neighbors = graph.get(course) || [];

            for (const neighbor of neighbors) {
                if (!dfs(neighbor)) return false;
            }

            states[course] = CourseScheduleII_210.VISITED;
            order.push(course); // Add course to order as it completes
            return true;
        };

        for (let i = 0; i < numCourses; i++) {
            if (states[i] === CourseScheduleII_210.UNVISITED && !dfs(i)) {
                return []; // If a cycle is detected, return an empty array
            }
        }

        return order;
    }
}

// Export the CourseScheduleII class
module.exports = CourseScheduleII_210;
