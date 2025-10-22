class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 1;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] <= 0 || (k != 0 && nums[k] == nums[k - 1])){
                continue;
            }
            else{
                if(nums[k] == i){
                    i++;
                }
                else{
                    return i;
                }
            }
        }
        return i;
    }
};