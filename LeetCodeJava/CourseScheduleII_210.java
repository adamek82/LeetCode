import java.util.*;

public class CourseScheduleII_210 {
    enum State { UNVISITED, VISITING, VISITED }
    private int index;

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] order = new int[numCourses];
        index = 0;  // Start filling the order array from the beginning
        Map<Integer, List<Integer>> graph = new HashMap<>();
        
        for (int[] prereq : prerequisites) {
            int course = prereq[0], pre = prereq[1];
            graph.computeIfAbsent(course, k -> new ArrayList<>()).add(pre);
        }

        State[] states = new State[numCourses];
        Arrays.fill(states, State.UNVISITED);
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, states, graph, order)) return new int[0]; // Return empty array if cycle is detected
        }

        return order;
    }

    private boolean dfs(int course, State[] states, Map<Integer, List<Integer>> graph, int[] order) {
        if (states[course] == State.VISITING) return false; // Cycle detected
        if (states[course] == State.VISITED) return true; // Already processed
        
        states[course] = State.VISITING;
        for (int neighbor : graph.getOrDefault(course, new ArrayList<>())) {
            if (!dfs(neighbor, states, graph, order)) return false;
        }

        states[course] = State.VISITED;
        order[index++] = course; // Place course in the correct order
        return true;
    }
}
