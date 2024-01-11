class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        ans = 0
        # dist[u][v] := the minimum distance to change ('a' + u) to ('a' + v)
        dist = [[float('inf')] * 26 for _ in range(26)]

        for i in range(len(cost)):
            u = ord(original[i]) - ord('a')
            v = ord(changed[i]) - ord('a')
            dist[u][v] = min(dist[u][v], cost[i])

        for k in range(26):
            for i in range(26):
                if dist[i][k] < float('inf'):
                    for j in range(26):
                        if dist[k][j] < float('inf'):
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        for i in range(len(source)):
            if source[i] == target[i]:
                continue
            u = ord(source[i]) - ord('a')
            v = ord(target[i]) - ord('a')
            if dist[u][v] == float('inf'):
                return -1
            ans += dist[u][v]

        return ans
