class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            maxCost -= std::abs(s[i] - t[i]);
            if (maxCost < 0) {
                maxCost += std::abs(s[j] - t[j]);
                ++j;
            }
        }

        return s.length() - j;
    }
};
