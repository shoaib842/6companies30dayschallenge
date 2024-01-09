class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::unordered_set<std::string> ans;
        std::unordered_set<std::string_view> seen;
        
        for (int i = 0; i + 10 <= s.length(); ++i) {
            std::string_view seq = s.substr(i, 10);
            if (seen.count(seq)) {
                ans.insert(seq);
            }
            seen.insert(seq);
        }

        return std::vector<std::string>(ans.begin(), ans.end());
    }
};
