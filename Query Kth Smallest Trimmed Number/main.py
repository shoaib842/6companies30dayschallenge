class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        ans = []
        for query in queries:
            ans.append(self.getKSmallestIndex(nums, query[0], query[1]))
        return ans

    def getKSmallestIndex(self, nums: List[str], k: int, trim: int) -> int:
        startIndex = len(nums[0]) - trim
        trimmed = [(num[startIndex:], i) for i, num in enumerate(nums)]
        trimmed.sort()
        return trimmed[k - 1][1]
