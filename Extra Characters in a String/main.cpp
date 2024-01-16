class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int n = s.length();
        std::unordered_set<std::string> dictionarySet(dictionary.begin(), dictionary.end());
        // dp[i]: the minimum extra letters if breaking up s[0..i) optimally
        std::vector<int> dp(n + 1, n);

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // s[j..i) is in `dictionarySet`
                if (dictionarySet.count(s.substr(j, i - j))) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
                // s[j..i) are extra letters
                else {
                    dp[i] = std::min(dp[i], dp[j] + i - j);
                }
            }
        }

        return dp[n];
    }
};
