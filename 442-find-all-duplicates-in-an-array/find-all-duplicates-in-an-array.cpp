class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> arr;
        int prev = -1;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != prev){
                prev = nums[i];
                count = 1;
                continue;
            }
            else {
                arr.push_back(nums[i]);
                count = 1;
            }
        }
        return arr;
    }
};