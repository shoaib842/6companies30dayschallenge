class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) {
            return {};
        }
        if (!node->left && !node->right) {
            return {1};
        }
        vector<int> left = dfs(node->left, distance, count);
        vector<int> right = dfs(node->right, distance, count);

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }

        vector<int> result;
        for (int n : left) {
            if (n + 1 < distance) {
                result.push_back(n + 1);
            }
        }
        for (int n : right) {
            if (n + 1 < distance) {
                result.push_back(n + 1);
            }
        }

        return result;
    }
};
