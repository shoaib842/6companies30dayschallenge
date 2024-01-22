class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int i = 0;
        for (int j = 0; i < g.size() && j < s.size(); ++j) {
            if (g[i] <= s[j]) {
                ++i;
            }
        }

        return i;
    }
};
