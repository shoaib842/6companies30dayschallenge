class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        n = len(aliceValues)
        values = list(zip(aliceValues, bobValues))
        a, b = 0, 0

        values.sort(key=lambda x: x[0] + x[1], reverse=True)

        for i in range(n):
            if i % 2 == 0:
                a += values[i][0]
            else:
                b += values[i][1]

        return 1 if a > b else -1 if a < b else 0
