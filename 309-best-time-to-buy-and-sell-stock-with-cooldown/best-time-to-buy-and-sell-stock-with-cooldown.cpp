class Solution {
private:
    int maxProfitHelper(vector<int>& prices, int index, int holding, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0; 
        }
        if (dp[index][holding] != -1) {
            return dp[index][holding];
        }
        int doNothing = maxProfitHelper(prices, index + 1, holding, dp);
        if (holding) {
            int sell = prices[index] + maxProfitHelper(prices, index + 2, 0, dp);
            return dp[index][holding] = max(doNothing, sell);
        } else {
            int buy = -prices[index] + maxProfitHelper(prices, index + 1, 1, dp);
            return dp[index][holding] = max(doNothing, buy);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfitHelper(prices, 0, 0, dp);
    }
};