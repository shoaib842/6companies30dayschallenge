class DataStream {
public:
    DataStream(int value, int k) : value(value), k(k) {}

    bool consec(int num) {
        if (q.size() == k) {
            if (q.front() == value) {
                --count;
            }
            q.pop_front();
        }

        if (num == value) {
            ++count;
        }

        q.push_back(num);
        return count == k;
    }

private:
    const int value;
    const int k;
    std::deque<int> q;
    int count = 0;
};
