class Solution {
public:
    std::vector<int> smallestTrimmedNumbers(std::vector<std::string>& nums,
                                            std::vector<std::vector<int>>& queries) {
        std::vector<int> ans;
        for (const std::vector<int>& query : queries) {
            ans.push_back(getKSmallestIndex(nums, query[0], query[1]));
        }
        return ans;
    }

private:
    int getKSmallestIndex(const std::vector<std::string>& nums, int k, int trim) {
        int startIndex = nums[0].length() - trim;
        std::vector<std::pair<std::string, int>> trimmed;  // (num, index)

        for (int i = 0; i < nums.size(); ++i) {
            const std::string& num = nums[i];
            trimmed.push_back({num.substr(startIndex), i});
        }

        std::sort(trimmed.begin(), trimmed.end());
        return trimmed[k - 1].second;
    }
};
