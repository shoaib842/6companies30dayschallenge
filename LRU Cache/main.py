class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        # Move the accessed key to the front.
        value = self.cache.pop(key)
        self.cache[key] = value
        return value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update the existing key and move it to the front.
            self.cache.pop(key)
        elif len(self.cache) == self.capacity:
            # Remove the least recently used key.
            self.cache.popitem(last=False)

        # Insert the new key-value pair.
        self.cache[key] = value
