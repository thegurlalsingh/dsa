class Solution {
    int solve(int i, int hold, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][hold] != -1){
            return dp[i][hold];
        }
        int skip = solve(i + 1, hold, prices, dp);
        int action = 0;
        if(hold == 0){
            action = -prices[i] + solve(i + 1, 1, prices, dp);
        }
        if(hold == 1){
            action = prices[i];
        }
        return dp[i][hold] = max(action, skip);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};