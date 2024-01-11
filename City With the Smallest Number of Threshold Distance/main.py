class Solution:
    def findTheCity(self, n, edges, distanceThreshold):
        ans = -1
        minCitiesCount = n
        dist = self.floydWarshall(n, edges, distanceThreshold)

        for i in range(n):
            citiesCount = 0
            for j in range(n):
                if dist[i][j] <= distanceThreshold:
                    citiesCount += 1
            if citiesCount <= minCitiesCount:
                ans = i
                minCitiesCount = citiesCount

        return ans

    def floydWarshall(self, n, edges, distanceThreshold):
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
