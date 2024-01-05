class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.count = 0

class Solution:
    def countDistinct(self, nums, k, p):
        self.root = TrieNode()
        ans = [0]  # Use a list to store a mutable value
        for i in range(len(nums)):
            self.insert(self.root, nums, i, k, p, ans)
        return ans[0]

    def insert(self, node, nums, i, k, p, ans):
        if i == len(nums) or k - (nums[i] % p == 0) < 0:
            return
        if nums[i] not in node.children:
            node.children[nums[i]] = TrieNode()
            ans[0] += 1
        self.insert(node.children[nums[i]], nums, i + 1, k - (nums[i] % p == 0), p, ans)
