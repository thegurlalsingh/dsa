class Solution {
    int solve(int i, vector<int>& prices, bool bought, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;

        if(dp[i][bought] != -1) return dp[i][bought];

        int skip = solve(i + 1, prices, bought, dp);

        int action = 0;
        if(!bought){
            // Buy today
            action = solve(i + 1, prices, true, dp) - prices[i];
        } else {
            // Sell today → profit and stop recursion
            action = prices[i];
        }

        return dp[i][bought] = max(skip, action);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, false, dp);
    }
};
