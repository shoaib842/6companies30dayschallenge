class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class T:
    def __init__(self, isBST=False, maximum=float('-inf'), minimum=float('inf'), totalSum=0):
        self.isBST = isBST
        self.max = maximum
        self.min = minimum
        self.sum = totalSum

class Solution:
    def maxSumBST(self, root):
        ans = [0]
        self.traverse(root, ans)
        return ans[0]

    def traverse(self, root, ans):
        if not root:
            return T(True, float('-inf'), float('inf'), 0)

        left = self.traverse(root.left, ans)
        right = self.traverse(root.right, ans)

        if not left.isBST or not right.isBST:
            return T()

        if root.val <= left.max or root.val >= right.min:
            return T()

        # The `root` is a valid BST.
        total_sum = root.val + left.sum + right.sum
        ans[0] = max(ans[0], total_sum)

        return T(True, max(root.val, right.max), min(root.val, left.min), total_sum)
