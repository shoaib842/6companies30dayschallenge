class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        ans = []
        bucket = [[] for _ in range(len(words) + 1)]
        count = Counter(words)

        for word, freq in count.items():
            bucket[freq].append(word)

        for freq in range(len(words), 0, -1):
            bucket[freq].sort()
            for word in bucket[freq]:
                ans.append(word)
                if len(ans) == k:
                    return ans
