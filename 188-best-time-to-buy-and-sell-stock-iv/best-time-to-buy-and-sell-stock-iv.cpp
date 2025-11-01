#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int solve(int i, vector<int>& prices, bool bought, int cap, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == 0) return 0;

        if (dp[i][bought][cap] != -1) return dp[i][bought][cap];

        int skip = solve(i + 1, prices, bought, cap, dp);
        int buy = 0, sell = 0;

        if (!bought) {
            buy = -prices[i] + solve(i + 1, prices, true, cap, dp);
        } else {
            sell = prices[i] + solve(i + 1, prices, false, cap - 1, dp);
        }

        return dp[i][bought][cap] = max({skip, buy, sell});
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, prices, false, k, dp);
    }
};