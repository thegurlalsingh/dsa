class Solution {
    int solve(int i, vector<int>& prices, bool hold, vector<vector<int>>& dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][hold] != -1){
            return dp[i][hold];
        }
        int take = 0, skip = 0, sell = 0;
        skip = solve(i + 1, prices, hold, dp);
        if(!hold){
            take = -prices[i] + solve(i + 1, prices, true, dp);
        }
        if(hold){
            sell = prices[i] + solve(i + 1, prices, false, dp);
        }
        return dp[i][hold] = max({take, skip, sell});
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, prices, false, dp);
    }
};