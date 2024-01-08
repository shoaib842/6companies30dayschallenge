class Solution:
    def minMoves2(self, nums):
        n = len(nums)
        nums.sort()
        median = nums[n // 2]
        return sum(abs(b - median) for b in nums)
