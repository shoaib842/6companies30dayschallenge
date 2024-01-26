class Solution {
public:
    int minNonZeroProduct(int p) {
        constexpr int kMod = 1'000'000'007;
        // Can always turn [1..2^p - 1] to [1, 1, ..., 2^p - 2, 2^p - 2, 2^p - 1].
        long long n = 1LL << p;
        long long halfCount = n / 2 - 1;
        return (modPow(n - 2, halfCount, kMod) * ((n - 1) % kMod)) % kMod;
    }

private:
    long long modPow(long long x, long long n, int mod) {
        if (n == 0) {
            return 1LL;
        }
        x %= mod;
        if (n % 2 == 1) {
            return (x * modPow(x, n - 1, mod)) % mod;
        }
        return modPow(x * x, n / 2, mod) % mod;
    }
};
