class Solution {
    bool solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size() - 1){
            return true;
        }

        // if(i >= n){
        //     return false;
        // }

        if(dp[i] != -1){
            return dp[i];
        }
        
        int ans = false;
        for(int idx = 1; idx <= nums[i]; idx++){
            if(i + idx < nums.size()){
                if(solve(i + idx, nums, dp)){
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};