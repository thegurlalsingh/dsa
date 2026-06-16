class Solution {
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][prev + 1] != -1){
            return dp[i][prev + 1];
        }
        int skip = solve(i + 1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + solve(i + 1, i, nums, dp);
        }
        return dp[i][prev + 1] = max(take, skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solve(0, -1, nums, dp);
    }
};