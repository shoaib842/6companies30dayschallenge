class Solution:
    def printMinNumberForPattern(self, S):
        n = len(S)
        result = ''
        stack = []

        # Iterate through the pattern and process each character
        for i in range(n + 1):
            # Push the current digit onto the stack
            stack.append(i + 1)

            # If 'I' is encountered or end of the pattern,
            # pop the digits from the stack and append to the result
            if i == n or S[i] == 'I':
                while stack:
                    result += str(stack.pop())

        return result
