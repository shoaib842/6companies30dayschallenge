class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::vector<std::vector<int>> ans(2);
        std::map<int, int> lossesCount;

        for (const auto& match : matches) {
            const int winner = match[0];
            const int loser = match[1];
            if (lossesCount.find(winner) == lossesCount.end()) {
                lossesCount[winner] = 0;
            }
            lossesCount[loser]++;
        }

        for (const auto& pair : lossesCount) {
            int player = pair.first;
            int nLosses = pair.second;
            if (nLosses < 2) {
                ans[nLosses].push_back(player);
            }
        }

        for (auto& list : ans) {
            std::sort(list.begin(), list.end());
        }

        return ans;
    }
};
