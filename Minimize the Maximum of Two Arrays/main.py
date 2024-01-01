class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        # Function to calculate the least common multiple of two numbers
        def lcm(x, y):
            return x * y // math.gcd(x, y)

        # Calculate the least common multiple of divisor1 and divisor2
        divisor_lcm = lcm(divisor1, divisor2)
        
        # Initialize left and right boundaries for binary search
        left, right = 0, 2**31 - 1

        # Function to check if it's possible to create two arrays with given conditions
        def is_possible(m: int) -> bool:
            cnt1 = m - m // divisor1
            cnt2 = m - m // divisor2
            total_cnt = m - m // divisor_lcm
            return cnt1 >= uniqueCnt1 and cnt2 >= uniqueCnt2 and total_cnt >= uniqueCnt1 + uniqueCnt2

        # Binary search to find the minimum possible value
        while left < right:
            mid = (left + right) // 2
            if is_possible(mid):
                right = mid
            else:
                left = mid + 1

        # Return the minimum value that satisfies the conditions
        return left
