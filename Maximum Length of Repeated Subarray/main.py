class Solution:
    def findLength(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        ans = 0
        # dp[i][j] := the maximum length of a subarray that appears in both
        # nums1[i:m] and nums2[j:n]
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if nums1[i] == nums2[j]:
                    dp[i][j] = dp[i + 1][j + 1] + 1
                    ans = max(ans, dp[i][j])

        return ans
