class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::vector<std::string> ans;
        int n = words.size();
        std::vector<std::vector<std::string>> bucket(n + 1);

        std::unordered_map<std::string, int> count;
        for (const std::string& word : words) {
            ++count[word];
        }

        for (const auto& [word, freq] : count) {
            bucket[freq].push_back(word);
        }

        for (int i = n; i > 0; --i) {
            std::sort(bucket[i].begin(), bucket[i].end());
            for (const std::string& word : bucket[i]) {
                ans.push_back(word);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        throw std::logic_error("Unexpected code path");
    }
};
