class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<int> dirs{0, 1, 0, -1, 0};
        vector<vector<int>> ans(m, vector<int>(n, -1));
        deque<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.emplace_back(i, j);
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x < 0 || x == m || y < 0 || y == n) {
                    continue;
                }
                if (ans[x][y] != -1) {
                    continue;
                }
                ans[x][y] = ans[i][j] + 1;
                q.emplace_back(x, y);
            }
        }

        return ans;
    }
};
