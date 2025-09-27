class Solution {
    int binarySearch(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                result = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;   
            }
        }
        return result;
    }

public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int m = binarySearch(nums, nums[i] + nums[j]);
                if (m == -1) {
                    count += (n - (j + 1));
                } else if (m > j) {
                    count += (m - (j + 1));
                }
            }
        }
        return count;
    }
};
