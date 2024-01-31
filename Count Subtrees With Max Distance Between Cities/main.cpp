class Solution {
public:
    std::vector<int> countSubgraphsForEachDiameter(int n, std::vector<std::vector<int>>& edges) {
        const int maxMask = 1 << n;
        std::vector<std::vector<int>> dist = floydWarshall(n, edges);
        std::vector<int> ans(n - 1);

        // mask := the subset of the cities
        for (int mask = 0; mask < maxMask; ++mask) {
            const int maxDist = getMaxDist(mask, dist, n);
            if (maxDist > 0)
                ++ans[maxDist - 1];
        }

        return ans;
    }

private:
    std::vector<std::vector<int>> floydWarshall(int n, const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, n));

        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;

        for (const auto& edge : edges) {
            const int u = edge[0] - 1;
            const int v = edge[1] - 1;
            dist[u][v] = 1;
            dist[v][u] = 1;
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

        return dist;
    }

    int getMaxDist(int mask, const std::vector<std::vector<int>>& dist, int n) {
        int maxDist = 0;
        int edgeCount = 0;
        int cityCount = 0;
        for (int u = 0; u < n; ++u) {
            if ((mask >> u & 1) == 0)  // u is not in the subset.
                continue;
            ++cityCount;
            for (int v = u + 1; v < n; ++v) {
                if ((mask >> v & 1) == 0)  // v is not in the subset.
                    continue;
                if (dist[u][v] == 1)  // u and v are connected.
                    ++edgeCount;
                maxDist = std::max(maxDist, dist[u][v]);
            }
        }
        return edgeCount == cityCount - 1 ? maxDist : 0;
    }
};
