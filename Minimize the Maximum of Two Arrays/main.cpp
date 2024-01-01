class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        // Function to calculate the least common multiple of two numbers
        auto lcm = [](int x, int y) {
            return x * y / std::gcd(x, y);
        };

        // Calculate the least common multiple of divisor1 and divisor2
        int divisor_lcm = lcm(divisor1, divisor2);

        // Initialize left and right boundaries for binary search
        int left = 0, right = std::pow(2, 31) - 1;

        // Function to check if it's possible to create two arrays with given conditions
        auto is_possible = [&](int m) {
            int cnt1 = m - m / divisor1;
            int cnt2 = m - m / divisor2;
            int total_cnt = m - m / divisor_lcm;
            return cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && total_cnt >= uniqueCnt1 + uniqueCnt2;
        };

        // Binary search to find the minimum possible value
        while (left < right) {
            int mid = (left + right) / 2;
            if (is_possible(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Return the minimum value that satisfies the conditions
        return left;
    }
};
