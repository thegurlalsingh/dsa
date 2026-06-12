class Solution {
    int solve(int i, vector<int>& prices,   vector<vector<vector<int>>>& dp, bool bought, int k){
        if(i >= prices.size()){
            return 0;
        }
        // if(k == 0){
        //     return 0;
        // }
        if(dp[i][bought][k] != -1){
            return dp[i][bought][k];
        }
        int skip = solve(i + 1, prices, dp, bought, k);
        int buy = 0;
        int sold = 0;
        if(!bought && k > 0){
            buy = -prices[i] + solve(i + 1, prices, dp, true, k);
        }
        if(bought){
            sold = prices[i] + solve(i + 1, prices, dp, false, k - 1);
        }

        return dp[i][bought][k] = max({skip, buy, sold});
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, prices, dp, false, k);
    }
};