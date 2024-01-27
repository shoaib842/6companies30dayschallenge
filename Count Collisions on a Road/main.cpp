class Solution {
public:
    int countCollisions(std::string directions) {
        int l = 0;
        int r = directions.length() - 1;

        while (l < directions.length() && directions[l] == 'L') {
            ++l;
        }

        while (r >= 0 && directions[r] == 'R') {
            --r;
        }

        int count = 0;
        for (int i = l; i <= r; ++i) {
            if (directions[i] != 'S') {
                ++count;
            }
        }

        return count;
    }
};
