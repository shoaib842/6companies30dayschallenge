class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int kMod = 1'000'000'007;
        long share = 0;
        // dp[i] := the number of people who know the secret at day i
        std::vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (i - delay >= 0) {
                share += dp[i - delay];
            }
            if (i - forget >= 0) {
                share -= dp[i - forget];
            }
            share = (share + kMod) % kMod;
            dp[i] = share;
        }

        // People before day `n - forget - 1` already forget the secret.
        return std::accumulate(dp.end() - forget, dp.end(), 0, [&](int subtotal, int d) {
            return (subtotal + d) % kMod;
        });
    }
};
