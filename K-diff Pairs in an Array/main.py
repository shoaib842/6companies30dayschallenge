class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        ans = 0
        num_to_index = {}

        for i, num in enumerate(nums):
            num_to_index[num] = i

        for i, num in enumerate(nums):
            target = num + k
            if target in num_to_index and num_to_index[target] != i:
                ans += 1
                del num_to_index[target]

        return ans
