class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;
        while (low <= high) {
            int mid = (high + low)/2;

            if (nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]); // for left part, if its sorted then element at low will be minimum
                low = mid + 1;
            } else {
                high = mid - 1;
                mini = min(mini, nums[mid]); // if right part is sorted, then element at mid would be minimum
            }
        }
        return mini;
    }
};