class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        int ans = 0;
        std::vector<int> count(121, 0);

        for (int age : ages) {
            ++count[age];
        }

        for (int i = 15; i <= 120; ++i) {
            ans += count[i] * (count[i] - 1);
        }

        for (int i = 15; i <= 120; ++i) {
            for (int j = i / 2 + 8; j < i; ++j) {
                ans += count[i] * count[j];
            }
        }

        return ans;
    }
};
