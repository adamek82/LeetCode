import java.util.*;

public class CourseSchedule_207 {
    enum State { UNVISITED, VISITING, VISITED }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] pair : prerequisites) {
            graph.computeIfAbsent(pair[0],k -> new ArrayList<>()).add(pair[1]);
        }

        State[] states = new State[numCourses];
        Arrays.fill(states, State.UNVISITED);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, graph, states) ) {
                return false;
            }
        }

        return true;
    }

    private boolean dfs(int node, Map<Integer, List<Integer>> graph, State[] states) {
        if (states[node] == State.VISITING) return false;
        if (states[node] == State.VISITED) return true;

        states[node] = State.VISITING;
        List<Integer> neighbors = graph.getOrDefault(node, Collections.emptyList());

        for (int neighbor : neighbors) {
            if (!dfs(neighbor, graph, states)) {
                return false;
            }
        }

        states[node] = State.VISITED;
        return true;
    }
}
