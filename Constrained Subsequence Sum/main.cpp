class Solution {
public:
    int constrainedSubsetSum(std::vector<int>& nums, int k) {
        // dp[i] := the maximum sum of non-empty subsequences in nums[0..i]
        std::vector<int> dp(nums.size());
        // dq stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0
        // in decreasing order.
        std::deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty()) {
                dp[i] = std::max(dq.front(), 0) + nums[i];
            } else {
                dp[i] = nums[i];
            }

            while (!dq.empty() && dq.back() < dp[i]) {
                dq.pop_back();
            }

            dq.push_back(dp[i]);

            if (i >= k && dp[i - k] == dq.front()) {
                dq.pop_front();
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
