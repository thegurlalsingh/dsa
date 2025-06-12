class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;

        for (int i = 0; i < n; i++) {
            int nextIndex = (i + 1) % n; 
            maxDiff = max(maxDiff, abs(nums[i] - nums[nextIndex]));
        }
        return maxDiff;
    }
};