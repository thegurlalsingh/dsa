class Solution {
    int solve7(int i, int amount, const vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }
        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = solve7(i - 1, amount, coins, dp);
        int take = 1e9;
        if (coins[i] <= amount) take = 1 + solve7(i, amount - coins[i], coins, dp);

        return dp[i][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve7(n - 1, amount, coins, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};