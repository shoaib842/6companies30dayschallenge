class Solution:
    def combinationSum3(self, k: int, target_sum: int) -> List[List[int]]:
        result = []

        def backtrack(remaining_count: int, remaining_sum: int, start: int, current_combination: List[int]) -> None:
            if remaining_count == 0 and remaining_sum == 0:
                result.append(current_combination[:])
                return
            if remaining_count == 0 or remaining_sum < 0:
                return

            for num in range(start, 10):
                current_combination.append(num)
                backtrack(remaining_count - 1, remaining_sum - num, num + 1, current_combination)
                current_combination.pop()

        backtrack(k, target_sum, 1, [])
        return result
