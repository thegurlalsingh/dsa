class Solution {
    int solve(int idx, vector<int>& nums, vector<int>& dp){
        if(idx >= nums.size() - 1){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }

        int ans = 1e9;
        for(int i = 1; i <= nums[idx]; i++){
            if(idx + i < nums.size()){
                ans = min(ans, 1 + solve(idx + i, nums, dp));   
            }
        }

        return dp[idx] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int k = solve(0, nums, dp);
        return k;
    }
};