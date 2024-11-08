from typing import List

class FindIfPathExistsInGraph_1971:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True

        # Create adjacency list
        graph = [[] for _ in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        # Use a list to mark visited nodes
        visited = [False] * n
        visited[source] = True

        return self.dfs(source, destination, graph, visited)

    def dfs(self, node: int, destination: int, graph: List[List[int]], visited: List[bool]) -> bool:
        if node == destination:
            return True

        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                if self.dfs(neighbor, destination, graph, visited):
                    return True

        return False
