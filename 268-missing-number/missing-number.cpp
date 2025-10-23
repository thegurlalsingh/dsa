class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] != i){
                return i;
            }
            else{
                i++;
            }
        }
        return nums.size();
    }
};