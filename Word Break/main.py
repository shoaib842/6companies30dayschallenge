class Solution:
    def wordBreak(self, s, wordDict):
        return self.wordBreakHelper(s, set(wordDict), {})

    def wordBreakHelper(self, s, wordSet, memo):
        if s in wordSet:
            return True
        if s in memo:
            return memo[s]

        # 1 <= len(prefix) < len(s)
        for i in range(1, len(s)):
            prefix = s[:i]
            suffix = s[i:]
            if prefix in wordSet and self.wordBreakHelper(suffix, wordSet, memo):
                memo[s] = True
                return True

        memo[s] = False
        return False
