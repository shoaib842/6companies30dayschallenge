class Solution {
public:
    int shoppingOffers(std::vector<int>& price, std::vector<std::vector<int>>& special, std::vector<int>& needs) {
        return dfs(price, special, needs, 0);
    }

private:
    int dfs(const std::vector<int>& price, const std::vector<std::vector<int>>& special, std::vector<int>& needs, int s) {
        int ans = 0;
        for (int i = 0; i < needs.size(); ++i) {
            ans += needs[i] * price[i];
        }

        for (int i = s; i < special.size(); ++i) {
            const std::vector<int>& offer = special[i];
            if (isValid(offer, needs)) {
                // Use the special[i].
                for (int j = 0; j < needs.size(); ++j) {
                    needs[j] -= offer[j];
                }
                ans = std::min(ans, offer.back() + dfs(price, special, needs, i));
                // Unuse the special[i] (backtracking).
                for (int j = 0; j < needs.size(); ++j) {
                    needs[j] += offer[j];
                }
            }
        }

        return ans;
    }

    // Returns true if this special offer is a valid one.
    bool isValid(const std::vector<int>& offer, const std::vector<int>& needs) {
        for (int i = 0; i < needs.size(); ++i) {
            if (offer[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }
};
