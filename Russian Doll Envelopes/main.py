class Solution:
    def maxEnvelopes(self, envelopes):
        envelopes.sort(key=lambda x: (x[0], -x[1]))

        # Same as 300. Longest Increasing Subsequence
        ans = 0
        dp = [0] * len(envelopes)

        for e in envelopes:
            l, r = 0, ans
            while l < r:
                m = (l + r) // 2
                if dp[m] >= e[1]:
                    r = m
                else:
                    l = m + 1
            dp[l] = e[1]
            if l == ans:
                ans += 1

        return ans
