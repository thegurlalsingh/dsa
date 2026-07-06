class Solution {
    long long solve(int i, vector<int>& nums, vector<int>& colors, vector<long long>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        long long skip = solve(i + 1, nums, colors, dp);
        long long take = 0;
        if(i + 1 < nums.size() && colors[i] == colors[i + 1]){
            take = nums[i] + solve(i + 2, nums, colors, dp);
        }
        else{
            take = nums[i] + solve(i + 1, nums, colors, dp);
        }

        return dp[i] = max(take, skip);
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size(), -1);
        return solve(0, nums, colors, dp);
    }
};