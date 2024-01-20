class Solution {
public:
    std::vector<std::vector<int>> getSkyline(const std::vector<std::vector<int>>& buildings) {
        int n = buildings.size();
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            int left = buildings[0][0];
            int right = buildings[0][1];
            int height = buildings[0][2];
            return {{left, height}, {right, 0}};
        }

        auto left = getSkyline(std::vector<std::vector<int>>(buildings.begin(), buildings.begin() + n / 2));
        auto right = getSkyline(std::vector<std::vector<int>>(buildings.begin() + n / 2, buildings.end()));
        return merge(left, right);
    }

private:
    std::vector<std::vector<int>> merge(const std::vector<std::vector<int>>& left,
                                        const std::vector<std::vector<int>>& right) {
        std::vector<std::vector<int>> ans;
        int i = 0;  // left's index
        int j = 0;  // right's index
        int leftY = 0;
        int rightY = 0;

        while (i < left.size() && j < right.size()) {
            // Choose the point with the smaller x.
            if (left[i][0] < right[j][0]) {
                leftY = left[i][1];  // Update the ongoing `leftY`.
                addPoint(ans, left[i][0], std::max(left[i++][1], rightY));
            } else {
                rightY = right[j][1];  // Update the ongoing `rightY`.
                addPoint(ans, right[j][0], std::max(right[j++][1], leftY));
            }
        }

        while (i < left.size()) {
            addPoint(ans, left[i][0], left[i++][1]);
        }

        while (j < right.size()) {
            addPoint(ans, right[j][0], right[j++][1]);
        }

        return ans;
    }

    void addPoint(std::vector<std::vector<int>>& ans, int x, int y) {
        if (!ans.empty() && ans.back()[0] == x) {
            ans.back()[1] = y;
            return;
        }
        if (!ans.empty() && ans.back()[1] == y) {
            return;
        }
        ans.push_back({x, y});
    }
};
