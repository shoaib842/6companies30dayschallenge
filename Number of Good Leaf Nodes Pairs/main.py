class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.ans = 0
        self.dfs(root, distance)
        return self.ans

    def dfs(self, root: TreeNode, d: int) -> List[int]:
        p = []
        if root is None:
            return p

        left = self.dfs(root.left, d)
        right = self.dfs(root.right, d)

        if len(left) == 0 and len(right) == 0:
            p.append(1)
            return p

        # Compare distance and add them to the answer
        for i in range(len(left)):
            for j in range(len(right)):
                if left[i] + right[j] <= d:
                    self.ans += 1

        # Increase distance by one for all children and send them to the parent
        for i in range(len(left)):
            left[i] += 1
            p.append(left[i])

        for i in range(len(right)):
            right[i] += 1
            p.append(right[i])

        return p
