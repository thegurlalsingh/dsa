class Solution {
    int solve(int i, vector<int>& prices, bool bought, vector<vector<int>>& dp, int fee){
        if(i >= prices.size()) return 0;

        if(dp[i][bought] != -1) return dp[i][bought];

        int skip = solve(i + 1, prices, bought, dp, fee);

        int action = 0;
        if(!bought){
            // Buy today
            action = solve(i + 1, prices, true, dp, fee) - prices[i] - fee;
        } else {
            // Sell today → profit and continue recursion
            action = prices[i] + solve(i + 1, prices, false, dp, fee);
        }

        return dp[i][bought] = max(skip, action);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, false, dp, fee);
    }
};