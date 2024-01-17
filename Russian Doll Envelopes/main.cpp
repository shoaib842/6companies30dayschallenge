class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        // Same as 300. Longest Increasing Subsequence
        int ans = 0;
        std::vector<int> dp(envelopes.size(), 0);

        for (const auto& e : envelopes) {
            int h = e[1];
            int l = 0;
            int r = ans;

            while (l < r) {
                int m = (l + r) / 2;
                if (dp[m] >= h)
                    r = m;
                else
                    l = m + 1;
            }

            dp[l] = h;
            if (l == ans)
                ++ans;
        }

        return ans;
    }
};
