class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def amountOfTime(self, root: TreeNode, start: int) -> int:
        ans = -1
        graph = self.getGraph(root)
        queue = deque([start])
        seen = {start}

        while queue:
            for _ in range(len(queue)):
                u = queue.popleft()
                if u not in graph:
                    continue
                for v in graph[u]:
                    if v in seen:
                        continue
                    queue.append(v)
                    seen.add(v)
            ans += 1

        return ans

    def getGraph(self, root: TreeNode) -> dict:
        graph = defaultdict(list)
        queue = deque([(root, -1)])  # (node, parent)

        while queue:
            node, parent = queue.popleft()
            if parent != -1:
                graph[parent].append(node.val)
                graph[node.val].append(parent)
            if node.left:
                queue.append((node.left, node.val))
            if node.right:
                queue.append((node.right, node.val))

        return graph
