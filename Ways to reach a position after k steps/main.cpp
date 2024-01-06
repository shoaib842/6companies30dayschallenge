class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // leftStep + rightStep = k
        // rightStep - leftStep = endPos - startPos
        // 2 * rightStep = k + endPos - startPos
        // rightStep = (k + endPos - startPos) / 2
        int val = k + endPos - startPos;
        if (val < 0 || val % 2 != 0) {
            return 0;
        }
        int rightStep = val / 2;
        int leftStep = k - rightStep;
        if (leftStep < 0) {
            return 0;
        }
        return _nCk(leftStep + rightStep, std::min(leftStep, rightStep));
    }

private:
    // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
    int _nCk(int n, int k) {
        const int kMod = 1'000'000'007;
        // dp[i] := C(n so far, i)
        std::vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int _ = 0; _ < n; ++_) {  // Calculate n times.
            for (int j = k; j > 0; --j) {
                dp[j] = (dp[j] + dp[j - 1]) % kMod;
            }
        }

        return dp[k];
    }
};
