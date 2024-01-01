class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        digit_to_letters = ['', '', 'abc', 'def', 'ghi',
                            'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        result = []

        def dfs(index: int, current_path: List[chr]) -> None:
            # If we have processed all digits, add the current combination to the result
            if index == len(digits):
                result.append(''.join(current_path))
                return

            # Iterate over the letters corresponding to the current digit
            current_digit = int(digits[index])
            for letter in digit_to_letters[current_digit]:
                # Choose the current letter and explore further
                current_path.append(letter)
                dfs(index + 1, current_path)
                # Backtrack: remove the last letter to explore other possibilities
                current_path.pop()

        # Start the DFS from the first digit
        dfs(0, [])
        return result
