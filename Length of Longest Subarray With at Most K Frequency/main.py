class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 0
        count = {}

        l = 0
        for r in range(len(nums)):
            count[nums[r]] = count.get(nums[r], 0) + 1

            while count[nums[r]] == k + 1:
                count[nums[l]] -= 1
                if count[nums[l]] == 0:
                    del count[nums[l]]
                l += 1

            ans = max(ans, r - l + 1)

        return ans
