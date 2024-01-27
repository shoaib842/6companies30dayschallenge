class Solution:
    def numberOfGoodSubsets(self, nums):
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        n = 1 << len(primes)
        max_num = max(nums)
        dp = [0] * n
        count = [0] * (max_num + 1)

        dp[0] = 1

        for num in nums:
            count[num] += 1

        for num in range(2, max_num + 1):
            if count[num] == 0:
                continue
            if num % 4 == 0 or num % 9 == 0 or num % 25 == 0:
                continue
            num_primes_mask = self.get_primes_mask(num, primes)
            for primes_mask in range(n):
                if (primes_mask & num_primes_mask) > 0:
                    continue
                next_primes_mask = primes_mask | num_primes_mask
                dp[next_primes_mask] += dp[primes_mask] * count[num]
                dp[next_primes_mask] %= 10**9 + 7

        return pow(2, count[1], 10**9 + 7) * (sum(dp[1:]) % (10**9 + 7)) % (10**9 + 7)

    def get_primes_mask(self, num, primes):
        primes_mask = 0
        for i, prime in enumerate(primes):
            if num % prime == 0:
                primes_mask |= 1 << i
        return primes_mask
