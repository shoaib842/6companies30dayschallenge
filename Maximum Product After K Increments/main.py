class Solution:
    def maximumProduct(self, nums, k):
        kMod = 1_000_000_007
        ans = 1
        minHeap = []

        for num in nums:
            heapq.heappush(minHeap, num)

        for i in range(k):
            minNum = heapq.heappop(minHeap)
            heapq.heappush(minHeap, minNum + 1)

        while minHeap:
            ans *= heapq.heappop(minHeap)
            ans %= kMod

        return ans
