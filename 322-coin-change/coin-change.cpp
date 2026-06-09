class Solution {
    int solve(int amount, vector<int>& coins, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }

        int t = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int temp = solve(amount - coins[i], coins, dp);
            if(temp != INT_MAX){
                t = min(t, temp + 1);
            }
        }

        return dp[amount] = t;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int a = accumulate(coins.begin(), coins.end(), 0);
        vector<int> dp(amount + 1, -1);
        int ans = solve(amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};