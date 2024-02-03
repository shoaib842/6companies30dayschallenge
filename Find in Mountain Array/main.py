class Solution:
    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        n = mountainArr.length()
        peakIndex = self.peakIndexInMountainArray(mountainArr, 0, n - 1)

        leftIndex = self.searchLeft(mountainArr, target, 0, peakIndex)
        if mountainArr.get(leftIndex) == target:
            return leftIndex

        rightIndex = self.searchRight(mountainArr, target, peakIndex + 1, n - 1)
        if mountainArr.get(rightIndex) == target:
            return rightIndex

        return -1

    # 852. Peak Index in a Mountain Array
    def peakIndexInMountainArray(self, A, l, r):
        while l < r:
            m = (l + r) // 2
            if A.get(m) < A.get(m + 1):
                l = m + 1
            else:
                r = m
        return l

    def searchLeft(self, A, target, l, r):
        while l < r:
            m = (l + r) // 2
            if A.get(m) < target:
                l = m + 1
            else:
                r = m
        return l

    def searchRight(self, A, target, l, r):
        while l < r:
            m = (l + r) // 2
            if A.get(m) > target:
                l = m + 1
            else:
                r = m
        return l
