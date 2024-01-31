class Solution:
    def minDays(self, grid):
        if self.disconnected(grid):
            return 0

        # Try to remove 1 land.
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if self.disconnected(grid):
                        return 1
                    grid[i][j] = 1

        # Remove 2 lands.
        return 2

    def disconnected(self, grid):
        islands_count = 0
        seen = [[False] * len(grid[0]) for _ in range(len(grid))]
        
        def dfs(i, j):
            nonlocal seen
            seen[i][j] = True
            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                x, y = i + dx, j + dy
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 1 and not seen[x][y]:
                    dfs(x, y)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0 or seen[i][j]:
                    continue
                if islands_count + 1 > 1:
                    return True
                islands_count += 1
                dfs(i, j)

        return islands_count != 1
