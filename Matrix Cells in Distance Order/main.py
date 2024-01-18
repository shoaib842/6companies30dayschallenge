class Solution:
    def allCellsDistOrder(self, rows, cols, rCenter, cCenter):
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ans = []
        seen = [[False] * cols for _ in range(rows)]
        q = deque([(rCenter, cCenter)])
        seen[rCenter][cCenter] = True

        while q:
            i, j = q.popleft()
            ans.append([i, j])

            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < rows and 0 <= y < cols and not seen[x][y]:
                    seen[x][y] = True
                    q.append((x, y))

        return ans
