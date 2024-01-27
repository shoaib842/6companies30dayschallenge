class Solution:
    def findTheDistanceValue(self, arr1, arr2, d):
        ans = 0

        arr2.sort()

        for a in arr1:
            it = bisect_left(arr2, a)
            if ((it == len(arr2) or arr2[it] - a > d) and
                    (it == 0 or a - arr2[it - 1] > d)):
                ans += 1

        return ans
