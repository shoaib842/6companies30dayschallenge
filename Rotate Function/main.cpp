class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int f = 0;
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            f += i * nums[i];
            sum += nums[i];
        }

        ans = f;

        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            f += sum - nums.size() * (*it);
            ans = std::max(ans, f);
        }

        return ans;
    }
};
