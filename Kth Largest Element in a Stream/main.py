class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.min_heap = []
        for num in nums:
            self.heapify(num)

    def add(self, val: int) -> int:
        self.heapify(val)
        return self.min_heap[0]

    def heapify(self, val: int) -> None:
        heapq.heappush(self.min_heap, val)
        if len(self.min_heap) > self.k:
            heapq.heappop(self.min_heap)
