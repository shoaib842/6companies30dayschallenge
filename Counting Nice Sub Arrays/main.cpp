class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
    }

private:
    int numberOfSubarraysAtMost(std::vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;

        while (r <= nums.size()) {
            if (k >= 0) {
                ans += r - l;
                if (r == nums.size()) {
                    break;
                }
                if (nums[r] & 1) {
                    k -= 1;
                }
                r += 1;
            } else {
                if (nums[l] & 1) {
                    k += 1;
                }
                l += 1;
            }
        }

        return ans;
    }
};
