class Solution:
    def maxNumberOfFamilies(self, n, reservedSeats):
        ans = 0
        row_to_seats = {}

        for reserved_seat in reservedSeats:
            row, seat = reserved_seat[0], reserved_seat[1]
            row_to_seats[row] = row_to_seats.get(row, 0) | (1 << (seat - 1))

        for _, seats in row_to_seats.items():
            if (seats & 0b0111111110) == 0:
                # Can fit 2 four-person groups.
                ans += 2
            elif (seats & 0b0111100000) == 0 or \
                 (seats & 0b0001111000) == 0 or \
                 (seats & 0b0000011110) == 0:
                # Can fit 1 four-person group.
                ans += 1

        # Any empty row can fit 2 four-person groups.
        return ans + (n - len(row_to_seats)) * 2
