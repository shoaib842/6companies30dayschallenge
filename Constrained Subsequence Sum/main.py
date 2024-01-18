class Solution:
    def constrainedSubsetSum(self, nums, k):
        dp = [0] * len(nums)
        dq = deque()

        for i in range(len(nums)):
            if not dq:
                dp[i] = nums[i]
            else:
                dp[i] = max(dq[0], 0) + nums[i]
            
            while dq and dq[-1] < dp[i]:
                dq.pop()

            dq.append(dp[i])

            if i >= k and dp[i - k] == dq[0]:
                dq.popleft()

        return max(dp)
