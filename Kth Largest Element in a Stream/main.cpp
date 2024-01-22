class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (const int num : nums)
            heapify(num);
    }

    int add(int val) {
        heapify(val);
        return minHeap.top();
    }

private:
    const int k;
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;

    void heapify(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
    }
};
