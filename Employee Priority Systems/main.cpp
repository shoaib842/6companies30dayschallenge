class Solution {
public:
    std::vector<std::string> findHighAccessEmployees(std::vector<std::vector<std::string>>& access_times) {
        std::unordered_set<std::string> ans;

        std::sort(access_times.begin(), access_times.end());

        for (size_t i = 0; i < access_times.size() - 2; ++i) {
            std::string name = access_times[i][0];
            if (ans.find(name) != ans.end()) {
                continue;
            }
            if (name != access_times[i + 2][0]) {
                continue;
            }
            if (std::stoi(access_times[i + 2][1]) - std::stoi(access_times[i][1]) < 100) {
                ans.insert(name);
            }
        }

        return std::vector<std::string>(ans.begin(), ans.end());
    }
};
