class Solution {
public:
    int wordCount(const std::vector<std::string>& startWords, const std::vector<std::string>& targetWords) {
        int ans = 0;
        std::unordered_set<int> seen;

        for (const std::string& w : startWords) {
            seen.insert(getMask(w));
        }

        for (const std::string& targetWord : targetWords) {
            int mask = getMask(targetWord);
            for (char c : targetWord) {
                // Toggle one character.
                if (seen.count(mask ^ (1 << (c - 'a')))) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }

private:
    int getMask(const std::string& s) {
        int mask = 0;
        for (char c : s) {
            mask ^= 1 << (c - 'a');
        }
        return mask;
    }
};
