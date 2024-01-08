class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        return std::accumulate(nums.begin(), nums.end(), 0,
                               [&](int a, int b) { return a + std::abs(b - median); });
    }
};
