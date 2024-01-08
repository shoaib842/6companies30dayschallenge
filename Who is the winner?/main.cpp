class Solution {
public:
    int findTheWinner(int n, int k) {
        // True if i-th friend is left
        std::vector<bool> friends(n, false);

        int friendCount = n;
        int fp = 0;  // friends' index

        while (friendCount > 1) {
            for (int i = 0; i < k; ++i) {
                while (friends[fp % n]) {  // The friend is not there.
                    ++fp;  // Point to the next one.
                }
                ++fp;
            }

            friends[(fp - 1) % n] = true;
            --friendCount;
        }

        fp = 0;
        while (friends[fp]) {
            ++fp;
        }

        return fp + 1;
    }
};
