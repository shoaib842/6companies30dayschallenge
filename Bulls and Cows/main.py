class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = 0
        B = 0
        count1 = [0] * 10
        count2 = [0] * 10

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                A += 1
            else:
                count1[int(secret[i])] += 1
                count2[int(guess[i])] += 1

        for i in range(10):
            B += min(count1[i], count2[i])

        return f"{A}A{B}B"
