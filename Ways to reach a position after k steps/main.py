class Solution:
    def numberOfWays(self, startPos, endPos, k):
        # leftStep + rightStep = k
        # rightStep - leftStep = endPos - startPos
        # 2 * rightStep = k + endPos - startPos
        # rightStep = (k + endPos - startPos) / 2
        val = k + endPos - startPos
        if val < 0 or val % 2 != 0:
            return 0
        rightStep = val // 2
        leftStep = k - rightStep
        if leftStep < 0:
            return 0
        return self.nCk(leftStep + rightStep, min(leftStep, rightStep))

    def nCk(self, n, k):
        kMod = 1_000_000_007
        # dp[i] := C(n so far, i)
        dp = [0] * (k + 1)
        dp[0] = 1

        for _ in range(n):  # Calculate n times.
            for j in range(k, 0, -1):
                dp[j] += dp[j - 1]
                dp[j] %= kMod

        return dp[k]
