class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        def compare(a, b):
            return (a[0] == b[0] and a[1] - b[1]) or a[0] - b[0]

        def cross(p, q, r):
            return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])

        def build_hull(points):
            hull = []
            for tree in points:
                while len(hull) > 1 and cross(hull[-2], hull[-1], tree) > 0:
                    hull.pop()
                hull.append(tree)
            return hull

        trees.sort(key=lambda x: (x[0], x[1]))

        lower_hull = build_hull(trees)

        trees.sort(reverse=True, key=lambda x: (x[0], x[1]))

        upper_hull = build_hull(trees)

        return list(set(map(tuple, lower_hull + upper_hull)))
