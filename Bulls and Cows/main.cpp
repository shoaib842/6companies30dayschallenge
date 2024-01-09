class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        int bulls = std::inner_product(secret.begin(), secret.end(), guess.begin(), 0,
                                       std::plus<>(), std::equal_to<>());

        int bovine = 0;
        for (char x : std::set<char>(guess.begin(), guess.end())) {
            bovine += std::min(std::count(secret.begin(), secret.end(), x), std::count(guess.begin(), guess.end(), x));
        }

        return std::to_string(bulls) + "A" + std::to_string(bovine - bulls) + "B";
    }
};
