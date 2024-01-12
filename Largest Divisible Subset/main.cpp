class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans;
        std::vector<int> count(n, 1);
        std::vector<int> prevIndex(n, -1);
        int maxCount = 0;
        int index = -1;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && count[i] < count[j] + 1) {
                    count[i] = count[j] + 1;
                    prevIndex[i] = j;
                }
            }

            if (count[i] > maxCount) {
                maxCount = count[i];
                index = i;
            }
        }

        while (index != -1) {
            ans.push_back(nums[index]);
            index = prevIndex[index];
        }

        return ans;
    }
};
