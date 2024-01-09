class Solution:
    def __init__(self, rects):
        self.rects = rects
        self.areas = list(accumulate(self.get_area(r) for r in self.rects))

    def pick(self):
        target = random.randint(0, self.areas[-1] - 1)
        index = next(i for i, area in enumerate(self.areas) if area > target)
        r = self.rects[index]
        return [random.randint(r[0], r[2]), random.randint(r[1], r[3])]

    def get_area(self, r):
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1)
