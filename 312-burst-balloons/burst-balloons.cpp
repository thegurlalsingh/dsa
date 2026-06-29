class Solution {
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k = i; k <= j; k++){
            int left = solve(i, k - 1, nums, dp);
            int right = solve(k + 1, j, nums, dp);
            int cost = left + right + (nums[i - 1] * nums[k] * nums[j + 1]);
            ans = max(ans, cost);
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); // classic mcm template
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(1, nums.size() - 2, nums, dp);
    }
};