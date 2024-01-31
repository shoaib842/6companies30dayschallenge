class Solution:
    def countSubgraphsForEachDiameter(self, n, edges):
        max_mask = 1 << n
        dist = self.floydWarshall(n, edges)
        ans = [0] * (n - 1)

        for mask in range(max_mask):
            max_dist = self.getMaxDist(mask, dist, n)
            if max_dist > 0:
                ans[max_dist - 1] += 1

        return ans

    def floydWarshall(self, n, edges):
        dist = [[n] * n for _ in range(n)]

        for i in range(n):
            dist[i][i] = 0

        for edge in edges:
            u, v = edge[0] - 1, edge[1] - 1
            dist[u][v] = 1
            dist[v][u] = 1

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        return dist

    def getMaxDist(self, mask, dist, n):
        max_dist = 0
        edge_count = 0
        city_count = 0
        for u in range(n):
            if (mask >> u) & 1 == 0:
                continue  # u is not in the subset.
            city_count += 1
            for v in range(u + 1, n):
                if (mask >> v) & 1 == 0:
                    continue  # v is not in the subset.
                if dist[u][v] == 1:  # u and v are connected.
                    edge_count += 1
                max_dist = max(max_dist, dist[u][v])

        return max_dist if edge_count == city_count - 1 else 0
