class Solution {
public:
    int cal(int ext, int ind, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == nums.size()) {
            return nums[ext];
        }

        if(ind == nums.size()-1) {
            return max(nums[ext], nums[ind]);
        }

        if(dp[ind][ext] != -1) {
            return dp[ind][ext];
        }

        int f = max(nums[ind], nums[ind+1]) + cal(ext, ind+2, nums, dp);
        int s = max(nums[ext], nums[ind+1]) + cal(ind, ind+2, nums, dp);
        int t = max(nums[ext], nums[ind]) + cal(ind+1, ind+2, nums, dp);

        return dp[ind][ext] = min({f, s, t});
    }

    int minCost(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return cal(0, 1, nums, dp);
    }
};