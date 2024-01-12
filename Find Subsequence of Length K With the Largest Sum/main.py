class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        ans = []
        A = nums.copy()
        A.sort()
        threshold = A[-k]
        larger = sum(num > threshold for num in nums)
        equal = k - larger

        for num in nums:
            if num > threshold:
                ans.append(num)
            elif num == threshold and equal:
                ans.append(num)
                equal -= 1

        return ans
