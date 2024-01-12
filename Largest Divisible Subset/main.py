class Solution:
    def largestDivisibleSubset(self, nums):
        n = len(nums)
        ans = []
        size_ends_at = [1] * n
        prev_index = [-1] * n
        max_size = 0
        index = -1

        nums.sort()

        for i in range(n):
            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0 and size_ends_at[i] < size_ends_at[j] + 1:
                    size_ends_at[i] = size_ends_at[j] + 1
                    prev_index[i] = j

            if max_size < size_ends_at[i]:
                max_size = size_ends_at[i]
                index = i

        while index != -1:
            ans.append(nums[index])
            index = prev_index[index]

        return ans
