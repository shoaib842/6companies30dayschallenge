class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        # Can always turn [1..2^p - 1] to [1, 1, ..., 2^p - 2, 2^p - 2, 2^p - 1].
        n = 1 << p
        half_count = n // 2 - 1
        return self.mod_pow(n - 2, half_count) * ((n - 1) % self.k_mod) % self.k_mod

    k_mod = 10**9 + 7

    def mod_pow(self, x, n):
        if n == 0:
            return 1
        x %= self.k_mod
        if n % 2 == 1:
            return x * self.mod_pow(x, n - 1) % self.k_mod
        return self.mod_pow(x * x, n // 2) % self.k_mod
