class Solution:
    def numberOfSubarrays(self, nums, k):
        return self.numberOfSubarraysAtMost(nums, k) - self.numberOfSubarraysAtMost(nums, k - 1)

    def numberOfSubarraysAtMost(self, nums, k):
        ans = 0
        l = 0
        r = 0

        while r <= len(nums):
            if k >= 0:
                ans += r - l
                if r == len(nums):
                    break
                if nums[r] & 1:
                    k -= 1
                r += 1
            else:
                if nums[l] & 1:
                    k += 1
                l += 1

        return ans
