class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int ones = 0;
                int count = 0;
                for (int y = std::max(0, i - 1); y < std::min(m, i + 2); ++y) {
                    for (int x = std::max(0, j - 1); x < std::min(n, j + 2); ++x) {
                        ones += M[y][x];
                        count += 1;
                    }
                }
                ans[i][j] = ones / count;
            }
        }

        return ans;
    }
};
