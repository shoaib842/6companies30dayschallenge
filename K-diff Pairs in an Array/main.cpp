class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        int ans = 0;
        std::unordered_map<int, int> num_to_index;

        for (int i = 0; i < nums.size(); ++i) {
            num_to_index[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] + k;
            if (num_to_index.find(target) != num_to_index.end() && num_to_index[target] != i) {
                ans += 1;
                num_to_index.erase(target);
            }
        }

        return ans;
    }
};
