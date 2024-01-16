class Solution:
    def minExtraChar(self, s, dictionary):
        n = len(s)
        dictionarySet = set(dictionary)
        # dp[i]: the minimum extra letters if breaking up s[0..i) optimally
        dp = [n] * (n + 1)
        dp[0] = 0

        for i in range(1, n + 1):
            for j in range(i):
                # s[j..i) is in `dictionarySet`
                if s[j:i] in dictionarySet:
                    dp[i] = min(dp[i], dp[j])
                # s[j..i) are extra letters
                else:
                    dp[i] = min(dp[i], dp[j] + i - j)

        return dp[n]
