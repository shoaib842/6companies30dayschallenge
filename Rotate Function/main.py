class Solution:
    def maxRotateFunction(self, nums):
        _sum = sum(nums)
        f = sum(i * nums[i] for i in range(len(nums)))

        ans = f

        for i in range(len(nums) - 1, 0, -1):
            f += _sum - len(nums) * nums[i]
            ans = max(ans, f)

        return ans
