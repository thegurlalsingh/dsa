class Solution {
    int solve(int i, vector<int>& prices, vector<vector<vector<int>>>& dp,
              int bought, int k) {

        if (i == prices.size() || k == 0)
            return 0;

        if (dp[i][bought][k] != -1)
            return dp[i][bought][k];

        int ans = solve(i + 1, prices, dp, bought, k);

        if (bought == 0) {
            ans = max(ans, -prices[i] + solve(i + 1, prices, dp, 1, k));
        } else {
            ans = max(ans, prices[i] + solve(i + 1, prices, dp, 0, k - 1));
        }

        return dp[i][bought][k] = ans;
    }

public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return solve(0, prices, dp, 0, k);
    }
};