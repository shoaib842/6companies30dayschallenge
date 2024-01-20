
class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        int ans = 0;
        std::unordered_map<int, int> rowToSeats;

        for (const std::vector<int>& reservedSeat : reservedSeats) {
            int row = reservedSeat[0];
            int seat = reservedSeat[1];
            rowToSeats[row] |= 1 << (seat - 1);
        }

        for (const auto& entry : rowToSeats) {
            int seats = entry.second;
            if ((seats & 0b0111111110) == 0) {
                // Can fit 2 four-person groups.
                ans += 2;
            } else if ((seats & 0b0111100000) == 0 || 
                       (seats & 0b0001111000) == 0 || 
                       (seats & 0b0000011110) == 0) {
                // Can fit 1 four-person group.
                ans += 1;
            }
        }

        // Any empty row can fit 2 four-person groups.
        return ans + (n - rowToSeats.size()) * 2;
    }
};
