class Solution {
public:
    Solution(int n_rows, int n_cols)
        : rows(n_rows), cols(n_cols), total(n_rows * n_cols) {}

    std::vector<int> flip() {
        if (used.size() == total)
            return {};
        int index = rand() % total;
        while (used.count(index))
            index = ++index % total;
        used.insert(index);
        return {index / cols, index % cols};
    }

    void reset() {
        used.clear();
    }

private:
    std::unordered_set<int> used;
    int rows;
    int cols;
    int total;
};
