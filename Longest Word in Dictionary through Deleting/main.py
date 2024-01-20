class Solution:
    def findLongestWord(self, s, d):
        ans = ""

        for word in d:
            if self.isSubsequence(word, s):
                if len(word) > len(ans) or (len(word) == len(ans) and word < ans):
                    ans = word

        return ans

    def isSubsequence(self, a, b):
        i = 0
        for c in b:
            if i < len(a) and c == a[i]:
                i += 1
        return i == len(a)
