class Solution:
    def __init__(self, n_rows, n_cols):
        self.rows = n_rows
        self.cols = n_cols
        self.total = n_rows * n_cols
        self.used = set()

    def flip(self):
        if len(self.used) == self.total:
            return []
        index = random.randint(0, self.total - 1)
        while index in self.used:
            index = (index + 1) % self.total
        self.used.add(index)
        return [index // self.cols, index % self.cols]

    def reset(self):
        self.used = set()
