class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        int ans = -1;
        int minCitiesCount = n;
        auto dist = _floydWarshall(n, edges, distanceThreshold);

        for (int i = 0; i < n; ++i) {
            int citiesCount = std::count_if(dist[i].begin(), dist[i].end(), [distanceThreshold](int d) { return d <= distanceThreshold; });
            if (citiesCount <= minCitiesCount) {
                ans = i;
                minCitiesCount = citiesCount;
            }
        }

        return ans;
    }

private:
    std::vector<std::vector<int>> _floydWarshall(int n, const std::vector<std::vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, distanceThreshold + 1));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        return dist;
    }
};
