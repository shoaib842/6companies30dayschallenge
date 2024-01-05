class Solution:
    def highestPeak(self, isWater):
        m, n = len(isWater), len(isWater[0])
        dirs = [0, 1, 0, -1, 0]
        ans = [[-1] * n for _ in range(m)]
        queue = deque()

        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    queue.append((i, j))
                    ans[i][j] = 0

        while queue:
            i, j = queue.popleft()
            for k in range(4):
                x, y = i + dirs[k], j + dirs[k + 1]
                if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                    ans[x][y] = ans[i][j] + 1
                    queue.append((x, y))

        return ans
