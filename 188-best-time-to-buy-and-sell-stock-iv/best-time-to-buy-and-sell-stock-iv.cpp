class Solution {
private:
    int maxProfitHelper(vector<int>& prices, int index, int capping, int holding, vector<vector<vector<int>>>& dp) {
        if (index == prices.size() || capping == 0) {
            return 0; 
        }
        if (dp[index][capping][holding] != -1) {
            return dp[index][capping][holding];
        }
        int doNothing = maxProfitHelper(prices, index + 1, capping, holding, dp);
        if (holding) {
            int sell = prices[index] + maxProfitHelper(prices, index + 1, capping - 1, 0, dp);
            dp[index][capping][holding] = max(doNothing, sell);
        } else {
            int buy = -prices[index] + maxProfitHelper(prices, index + 1, capping, 1, dp);
            dp[index][capping][holding] = max(doNothing, buy);
        }
        return dp[index][capping][holding];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1))); 
        return maxProfitHelper(prices, 0, k, 0, dp);
    }
};