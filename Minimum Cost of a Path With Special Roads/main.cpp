class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        return dijkstra(specialRoads, start[0], start[1], target[0], target[1]);
    }

private:
    int dijkstra(vector<vector<int>>& specialRoads, int srcX, int srcY, int dstX, int dstY) {
        int n = specialRoads.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int u = 0; u < n; ++u) {
            int x1 = specialRoads[u][0];
            int y1 = specialRoads[u][1];
            int cost = specialRoads[u][4];
            int d = abs(x1 - srcX) + abs(y1 - srcY) + cost;
            dist[u] = d;
            minHeap.push({dist[u], u});
        }

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();
            int ux2 = specialRoads[u][2];
            int uy2 = specialRoads[u][3];

            for (int v = 0; v < n; ++v) {
                if (v == u) {
                    continue;
                }

                int vx1 = specialRoads[v][0];
                int vy1 = specialRoads[v][1];
                int vcost = specialRoads[v][4];
                int newDist = d + abs(vx1 - ux2) + abs(vy1 - uy2) + vcost;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    minHeap.push({dist[v], v});
                }
            }
        }

        int ans = abs(dstX - srcX) + abs(dstY - srcY);

        for (int u = 0; u < n; ++u) {
            int x2 = specialRoads[u][2];
            int y2 = specialRoads[u][3];
            ans = min(ans, dist[u] + abs(dstX - x2) + abs(dstY - y2));
        }

        return ans;
    }
};
