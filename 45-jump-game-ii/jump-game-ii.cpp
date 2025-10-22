class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size() - 1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int take = INT_MAX;
        for(int k = 1; k <= nums[i]; k++){
            if(i + k < nums.size()){
                int next =  solve(i + k, nums, dp);
                if(next != INT_MAX){
                    take = min(take, next + 1);
                }
            }
        }
        return dp[i] = take;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp); 
    }
};