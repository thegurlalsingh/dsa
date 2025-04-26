class Solution {
private:
    bool check(deque<int> &maxDq, deque<int> &minDq, int minK, int maxK, vector<int>& nums) {
        int maxVal = nums[maxDq.front()];
        int minVal = nums[minDq.front()];
        return (minVal == minK && maxVal == maxK);
    }

public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int i = 0, j = 0;
        long long count = 0;
        deque<int> maxDq, minDq;

        while (j < n) {
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[j]) {
                maxDq.pop_back();
            }
            maxDq.push_back(j);

            while (!minDq.empty() && nums[minDq.back()] >= nums[j]) {
                minDq.pop_back();
            }
            minDq.push_back(j);

            while ((!maxDq.empty() && !minDq.empty()) && (nums[maxDq.front()] > maxK || nums[minDq.front()] < minK)) {
                if (maxDq.front() == i) {
                    maxDq.pop_front();
                }
                if (minDq.front() == i) {
                    minDq.pop_front();
                }
                i++;
            }

            if (!maxDq.empty() && !minDq.empty() && nums[maxDq.front()] == maxK && nums[minDq.front()] == minK) {
                count += (min(maxDq.front(), minDq.front()) - i + 1);
            }

            j++;
        }

        return count;
    }
};
