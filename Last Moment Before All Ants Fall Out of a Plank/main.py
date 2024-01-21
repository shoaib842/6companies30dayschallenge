class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        maxLeft = max(left) if left else 0
        minRight = min(right) if right else n
        return max(maxLeft, n - minRight)
