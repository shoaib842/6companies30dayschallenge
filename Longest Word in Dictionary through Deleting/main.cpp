class Solution {
public:
    std::string findLongestWord(const std::string& s, const std::vector<std::string>& d) {
        std::string ans;

        for (const std::string& word : d) {
            int i = 0;
            for (char c : s) {
                if (i < word.length() && c == word[i]) {
                    ++i;
                }
            }
            if (i == word.length()) {
                if (word.length() > ans.length() || (word.length() == ans.length() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};
