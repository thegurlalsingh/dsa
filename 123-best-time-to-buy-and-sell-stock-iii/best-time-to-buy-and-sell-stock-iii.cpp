class Solution {
    int solve(int i, int hold, vector<int>& prices, vector<vector<vector<int>>>& dp, int k){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][hold][k] != -1){
            return dp[i][hold][k];
        }
        int skip = solve(i + 1, hold, prices, dp, k);
        int action = 0;
        if(hold == 0 && k > 0){
            action = -prices[i] + solve(i + 1, 1, prices, dp, k); // buy
        }
        if(hold == 1){
            action = prices[i] + solve(i + 1, 0, prices, dp, k - 1); // sell
        }
        return dp[i][hold][k] = max(action, skip);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 0, prices, dp, 2);
    }
};