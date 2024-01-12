class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = -1;
        std::unordered_map<int, std::vector<int>> graph = getGraph(root);
        std::queue<int> q{{start}};
        std::unordered_set<int> seen{start};

        while (!q.empty()) {
            ans++;
            for (int sz = q.size(); sz > 0; --sz) {
                int u = q.front();
                q.pop();
                if (graph.find(u) == graph.end()) {
                    continue;
                }
                for (int v : graph[u]) {
                    if (seen.find(v) != seen.end()) {
                        continue;
                    }
                    q.push(v);
                    seen.insert(v);
                }
            }
        }

        return ans;
    }

private:
    std::unordered_map<int, std::vector<int>> getGraph(TreeNode* root) {
        std::unordered_map<int, std::vector<int>> graph;
        std::queue<std::pair<TreeNode*, int>> q{{{root, -1}}};  // (node, parent)

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            if (parent != -1) {
                graph[parent].push_back(node->val);
                graph[node->val].push_back(parent);
            }
            if (node->left) {
                q.emplace(node->left, node->val);
            }
            if (node->right) {
                q.emplace(node->right, node->val);
            }
        }

        return graph;
    }
};
