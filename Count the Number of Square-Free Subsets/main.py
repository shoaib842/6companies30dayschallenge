class Solution:
    def __init__(self):
        self.kMod = 10**9 + 7
        self.kPrimesCount = 10
        self.primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

    def squareFreeSubsets(self, nums):
        mem = [[-1] * (1 << (self.kPrimesCount + 1)) for _ in range(len(nums))]
        masks = [self.getMask(num) for num in nums]
        return (self._squareFreeSubsets(masks, 0, 1, mem) - 1 + self.kMod) % self.kMod

    def _squareFreeSubsets(self, masks, i, used, mem):
        if i == len(masks):
            return 1
        if mem[i][used] != -1:
            return mem[i][used]
        pick = self._squareFreeSubsets(masks, i + 1, used | masks[i], mem) if (masks[i] & used) == 0 else 0
        skip = self._squareFreeSubsets(masks, i + 1, used, mem)
        mem[i][used] = (pick + skip) % self.kMod
        return mem[i][used]

    def getMask(self, num):
        mask = 0
        for i in range(len(self.primes)):
            rootCount = 0
            while num % self.primes[i] == 0:
                num //= self.primes[i]
                rootCount += 1
            if rootCount >= 2:
                return -1
            if rootCount == 1:
                mask |= 1 << i
        return mask << 1
