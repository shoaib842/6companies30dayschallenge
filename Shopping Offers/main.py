class Solution:
    def shoppingOffers(self, price, special, needs):
        return self.dfs(price, special, needs, 0)

    def dfs(self, price, special, needs, s):
        ans = sum(p * n for p, n in zip(price, needs))

        for i in range(s, len(special)):
            if self.isValid(special[i], needs):
                # Use the special[i].
                for j in range(len(needs)):
                    needs[j] -= special[i][j]
                ans = min(ans, special[i][-1] + self.dfs(price, special, needs, i))
                # Unuse the special[i] (backtracking).
                for j in range(len(needs)):
                    needs[j] += special[i][j]

        return ans

    # Returns True if this special offer is a valid one.
    def isValid(self, offer, needs):
        return all(need >= o for need, o in zip(needs, offer[:-1]))
