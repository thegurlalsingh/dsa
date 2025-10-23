class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int left = 0; // tracking positions where array elements should not be equal to val
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] != val){
                swap(nums[right], nums[left]);
                left++;
            }
        }
        int r = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                r = i;
                break;
            }
        }
        if(r == 0 && nums[0] != val){
            return nums.size();
        }
        else if(r == 0 && nums[0] == val){
            return 0;
        }
        return r;
    }
};