class TrieNode {
public:
    unordered_map<int, shared_ptr<TrieNode>> children;
    int count = 0;
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 0;
        shared_ptr<TrieNode> root = make_shared<TrieNode>();

        function<void(shared_ptr<TrieNode>, int, int)> insert = [&](shared_ptr<TrieNode> node, int i, int k) {
            if (i == nums.size() || k - (nums[i] % p == 0) < 0) {
                return;
            }
            if (node->children.find(nums[i]) == node->children.end()) {
                node->children[nums[i]] = make_shared<TrieNode>();
                ans += 1;
            }
            insert(node->children[nums[i]], i + 1, k - (nums[i] % p == 0));
        };

        for (int i = 0; i < nums.size(); ++i) {
            insert(root, i, k);
        }

        return ans;
    }
};
