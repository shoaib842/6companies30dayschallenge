class Solution:
    def wordCount(self, startWords, targetWords):
        ans = 0
        seen = set()

        for w in startWords:
            seen.add(self.getMask(w))

        for w in targetWords:
            mask = self.getMask(w)
            for c in w:
                # Toggle one character.
                if mask ^ (1 << (ord(c) - ord('a'))) in seen:
                    ans += 1
                    break

        return ans

    def getMask(self, s):
        mask = 0
        for c in s:
            mask ^= 1 << (ord(c) - ord('a'))
        return mask
