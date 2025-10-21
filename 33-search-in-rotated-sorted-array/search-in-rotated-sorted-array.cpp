class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int index = -1;
        while(i <= j){
            int mid = (i + j)/2;
            if(target == nums[mid]){
                index = mid;
                break;
            }
            if(nums[mid] <= nums[j]){ // right part is sorted
                if(nums[mid] < target && nums[j] >= target){
                    i = mid + 1;
                }
                else{
                    j = mid - 1;
                }
            }
            else{ // left part is sorted
                if(nums[mid] > target && nums[i] <= target){
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }
            }
        }
        return index;
    }
};