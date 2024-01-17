class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.depth = 0

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        ans = 0
        root = TrieNode()
        heads = []

        for word in set(words):
            heads.append(self.insert(root, word))

        for head in heads:
            if all(child is None for child in head.children):
                ans += head.depth + 1

        return ans

    def insert(self, root, word):
        node = root
        for c in reversed(word):
            i = ord(c) - ord('a')
            if node.children[i] is None:
                node.children[i] = TrieNode()
            node = node.children[i]
        node.depth = len(word)
        return node
