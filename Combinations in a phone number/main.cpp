class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector<std::string> digitToLetters = {"", "", "abc", "def", "ghi",
                                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> result;

        dfs(0, digits, "", digitToLetters, result);

        return result;
    }

private:
    void dfs(int index, const std::string& digits, std::string currentPath,
             const std::vector<std::string>& digitToLetters,
             std::vector<std::string>& result) {
        // If we have processed all digits, add the current combination to the result
        if (index == digits.length()) {
            result.push_back(currentPath);
            return;
        }

        // Iterate over the letters corresponding to the current digit
        int currentDigit = digits[index] - '0';
        for (char letter : digitToLetters[currentDigit]) {
            // Choose the current letter and explore further
            dfs(index + 1, digits, currentPath + letter, digitToLetters, result);
        }
    }
};
