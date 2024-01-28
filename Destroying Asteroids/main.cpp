class Solution {
public:
    bool asteroidsDestroyed(long long mass, std::vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {
            if (mass >= asteroid) {
                mass += asteroid;
            } else {
                return false;
            }
        }

        return true;
    }
};
