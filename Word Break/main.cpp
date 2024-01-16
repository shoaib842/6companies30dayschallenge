class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, wordSet);
    }

private:
    std::unordered_map<std::string, bool> memo;

    bool wordBreakHelper(const std::string& s, const std::unordered_set<std::string>& wordSet) {
        if (wordSet.count(s) > 0) {
            return true;
        }
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        for (int i = 1; i < s.length(); ++i) {
            std::string prefix = s.substr(0, i);
            std::string suffix = s.substr(i);
            if (wordSet.count(prefix) > 0 && wordBreakHelper(suffix, wordSet)) {
                memo[s] = true;
                return true;
            }
        }

        memo[s] = false;
        return false;
    }
};
