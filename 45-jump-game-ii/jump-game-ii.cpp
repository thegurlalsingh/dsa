class Solution {
    int solve(int i, vector<int>& dp, vector<int>& nums){
        if(i == nums.size() - 1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j = 1; j <= nums[i] && i + j < nums.size(); j++){
            int t = solve(j + i, dp, nums);
            if(t != INT_MAX){
                ans = min(ans, 1 + t);
            }   
        }
        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, dp, nums);
    }
};