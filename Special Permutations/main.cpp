class Solution {
public:
    int specialPerm(std::vector<int>& nums) {
        constexpr int kMod = 1'000'000'007;
        int maxMask = 1 << nums.size();
        std::unordered_map<int, int> memo;

        std::function<int(int, int)> dp = [&](int prev, int mask) -> int {
            if (mask == maxMask - 1) {
                return 1;
            }

            int key = prev * maxMask + mask;
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }

            int res = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (mask >> i & 1) {
                    continue;
                }

                if (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) {
                    res += dp(i, mask | 1 << i);
                    res %= kMod;
                }
            }

            memo[key] = res;
            return res;
        };

        int result = 0;

        for (int i = 0; i < nums.size(); ++i) {
            result += dp(i, 1 << i);
            result %= kMod;
        }

        return result;
    }
};
