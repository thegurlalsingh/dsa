class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int num : nums) {
            min_heap.push(num);
        }

        nums.clear();

        while (!min_heap.empty()) {
            nums.push_back(min_heap.top());
            min_heap.pop();
        }
    }
};
