class Solution:
    def maxProduct(self, s: str) -> int:
        ans = [0]
        self.dfs(s, 0, "", "", ans)
        return ans[0]

    def dfs(self, s, i, s1, s2, ans):
        if i == len(s):
            if self.isPalindrome(s1) and self.isPalindrome(s2):
                ans[0] = max(ans[0], len(s1) * len(s2))
            return

        self.dfs(s, i + 1, s1 + s[i], s2, ans)
        self.dfs(s, i + 1, s1, s2 + s[i], ans)
        self.dfs(s, i + 1, s1, s2, ans)

    def isPalindrome(self, s):
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
