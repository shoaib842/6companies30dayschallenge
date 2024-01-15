class Solution:
    def frequencySort(self, s: str) -> str:
        count = [0] * 128
        buckets = [[] for _ in range(len(s) + 1)]
        ans = ""

        for c in s:
            count[ord(c)] += 1

        for i in range(128):
            freq = count[i]
            if freq > 0:
                buckets[freq].append(chr(i))

        for freq in range(len(s), 0, -1):
            for c in buckets[freq]:
                ans += freq * c

        return ans
