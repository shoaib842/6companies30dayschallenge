class Solution {
public:
    int maximumProduct(std::vector<int>& nums, int k) {
        constexpr int kMod = 1'000'000'007;
        long ans = 1;
        std::vector<int> minHeap = nums;
        std::make_heap(minHeap.begin(), minHeap.end(), std::greater<int>());

        for (int i = 0; i < k; ++i) {
            int minNum = minHeap.front();
            std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
            minHeap.pop_back();
            minHeap.push_back(minNum + 1);
            std::push_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
        }

        while (!minHeap.empty()) {
            ans *= minHeap.front();
            ans %= kMod;
            std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
            minHeap.pop_back();
        }

        return ans;
    }
};
