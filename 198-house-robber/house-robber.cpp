class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int skip = solve(i + 1, nums, dp);
        int take = nums[i] + solve(i + 2, nums, dp);
        // if(i + 2 < nums.size()){
        //     take = nums[i] + solve(i + 2, nums, dp);
        // }

        return dp[i] = max(skip, take);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};