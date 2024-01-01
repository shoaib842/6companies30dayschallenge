class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int target_sum) {
        std::vector<std::vector<int>> result;

        // Helper function for backtracking
        std::function<void(int, int, int, std::vector<int>&)> backtrack =
            [&](int remaining_count, int remaining_sum, int start, std::vector<int>& current_combination) {
                // If a valid combination is found, append a copy to the result
                if (remaining_count == 0 && remaining_sum == 0) {
                    result.push_back(current_combination);
                    return;
                }

                // If the current combination is invalid, return
                if (remaining_count == 0 || remaining_sum < 0) {
                    return;
                }

                // Explore combinations by considering numbers starting from 'start'
                for (int num = start; num <= 9; ++num) {
                    current_combination.push_back(num);
                    // Recursively explore next combinations
                    backtrack(remaining_count - 1, remaining_sum - num, num + 1, current_combination);
                    // Backtrack by removing the last added element
                    current_combination.pop_back();
                }
            };

        // Start the backtracking process
        std::vector<int> current_combination;
        backtrack(k, target_sum, 1, current_combination);
        return result;
    }
};
