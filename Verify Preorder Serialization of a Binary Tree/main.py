class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        degree = 1  # out-degree (children) - in-degree (parent)
        nodes = preorder.split(',')

        for node in nodes:
            if degree == 0:
                return False
            if node != "#":
                degree += 1
            else:
                degree -= 1

        return degree == 0
