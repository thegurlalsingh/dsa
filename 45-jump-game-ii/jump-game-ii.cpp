class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size() - 1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 1e9;
        for(int end = 1; end < nums.size() && end <= nums[i]; end++){
            ans = min(ans, 1 + solve(i + end, nums, dp));
        }
        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};