class Solution {
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        for (const vector<int>& r : this->rects) {
            areas.push_back(getArea(r));
        }
        partial_sum(areas.begin(), areas.end(), areas.begin());
        srand(time(0));
    }

    vector<int> pick() {
        int target = rand() % areas.back();
        auto it = upper_bound(areas.begin(), areas.end(), target);
        int index = distance(areas.begin(), it);
        const vector<int>& r = rects[index];
        return {rand() % (r[2] - r[0] + 1) + r[0], rand() % (r[3] - r[1] + 1) + r[1]};
    }

private:
    vector<vector<int>> rects;
    vector<int> areas;

    int getArea(const vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
};
