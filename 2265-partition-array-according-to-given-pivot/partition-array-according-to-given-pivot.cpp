class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr(nums.size());
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                arr[j++] = nums[i];
            }
        }

        int pivotCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot) {
                pivotCount++;
            }
        }
        for (int i = 0; i < pivotCount; i++) {
            arr[j++] = pivot;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) {
                arr[j++] = nums[i];
            }
        }

        return arr;
    }
};
