class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> count;

        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            int num = nums[r];
            count[num]++;

            while (count[num] == k + 1) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
