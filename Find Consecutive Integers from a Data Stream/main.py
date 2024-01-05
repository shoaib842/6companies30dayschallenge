class DataStream:
    def __init__(self, value, k):
        self.value = value
        self.k = k
        self.q = deque()
        self.count = 0

    def consec(self, num):
        if len(self.q) == self.k:
            if self.q[0] == self.value:
                self.count -= 1
            self.q.popleft()

        if num == self.value:
            self.count += 1

        self.q.append(num)
        return self.count == self.k
