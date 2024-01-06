class Solution:
    def incremovableSubarrayCount(self, nums):
        n = len(nums)
        start_index = self.getStartIndexOfSuffix(nums)

        if start_index == 0:
            return n * (n + 1) // 2

        ans = n - start_index + 1

        for i in range(start_index):
            if i > 0 and nums[i] <= nums[i - 1]:
                break
            
            j = start_index
            while j < n and nums[i] >= nums[j]:
                j += 1

            ans += n - j + 1

        return ans

    def getStartIndexOfSuffix(self, nums):
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] >= nums[i + 1]:
                return i + 1
        return 0
