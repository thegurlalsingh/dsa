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
            return dp[index][capping][holding] = max(doNothing, sell);
        } else {
            int buy = -prices[index] + maxProfitHelper(prices, index + 1, capping, 1, dp);
            return dp[index][capping][holding] = max(doNothing, buy);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1))); 
        return maxProfitHelper(prices, 0, 2, 0, dp);
    }
};