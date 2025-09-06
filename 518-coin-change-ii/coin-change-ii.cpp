class Solution {
int solve7(int i, int amount, const vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (i >= coins.size()) {
            return 0;
        }
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int notTake = solve7(i + 1, amount, coins, dp);
        int take = 0;
        if (coins[i] <= amount) {
            take = solve7(i, amount - coins[i], coins, dp);
        }

        return dp[i][amount] = (take + notTake);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve7(0, amount, coins, dp);
        return ans;
    }
};