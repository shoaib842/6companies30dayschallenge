class Solution {
public:
    std::vector<std::vector<int>> outerTrees(std::vector<std::vector<int>>& trees) {
        std::vector<std::vector<int>> hull;

        std::sort(trees.begin(), trees.end(), [](const auto& a, const auto& b) {
            return std::tie(a[0], a[1]) < std::tie(b[0], b[1]);
        });

        auto cross = [](const std::vector<int>& p, const std::vector<int>& q, const std::vector<int>& r) {
            return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        };

        // Build the lower hull: left-to-right scan.
        for (const auto& tree : trees) {
            while (hull.size() > 1 && cross(hull.back(), hull[hull.size() - 2], tree) > 0) {
                hull.pop_back();
            }
            hull.push_back(tree);
        }
        hull.pop_back();

        // Build the upper hull: right-to-left scan.
        for (auto it = trees.rbegin(); it != trees.rend(); ++it) {
            const auto& tree = *it;
            while (hull.size() > 1 && cross(hull.back(), hull[hull.size() - 2], tree) > 0) {
                hull.pop_back();
            }
            hull.push_back(tree);
        }

        // Remove the redundant elements from the stack.
        std::set<std::vector<int>> uniqueHull(hull.begin(), hull.end());

        return std::vector<std::vector<int>>(uniqueHull.begin(), uniqueHull.end());
    }
};
