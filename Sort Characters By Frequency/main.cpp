class Solution {
public:
    std::string frequencySort(std::string s) {
        std::string ans;
        int n = s.length();
        std::vector<std::vector<char>> buckets(n + 1);

        std::unordered_map<char, int> count;
        for (char c : s) {
            ++count[c];
        }

        for (const auto& entry : count) {
            char c = entry.first;
            int freq = entry.second;
            buckets[freq].push_back(c);
        }

        for (int freq = n; freq > 0; --freq) {
            for (char c : buckets[freq]) {
                ans += std::string(freq, c);
            }
        }

        return ans;
    }
};
