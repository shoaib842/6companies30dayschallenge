class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        ans = -1
        min_cities_count = n
        dist = self.floyd_warshall(n, edges, distanceThreshold)

        for i in range(n):
            cities_count = sum(1 for j in range(n) if dist[i][j] <= distanceThreshold)
            if cities_count <= min_cities_count:
                ans = i
                min_cities_count = cities_count

        return ans

    def floyd_warshall(self, n: int, edges: List[List[int]], distanceThreshold: int) -> List[List[int]]:
        dist = [[distanceThreshold + 1] * n for _ in range(n)]

        for i in range(n):
            dist[i][i] = 0

        for edge in edges:
            u, v, w = edge
            dist[u][v] = w
            dist[v][u] = w

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        return dist
