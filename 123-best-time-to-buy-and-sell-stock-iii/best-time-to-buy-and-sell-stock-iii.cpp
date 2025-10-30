#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int bought = 0; bought <= 1; bought++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int skip = dp[i + 1][bought][cap];
                    int buy = 0, sell = 0;

                    if (!bought)
                        buy = -prices[i] + dp[i + 1][1][cap];
                    else
                        sell = prices[i] + dp[i + 1][0][cap - 1];

                    dp[i][bought][cap] = max({skip, buy, sell});
                }
            }
        }

        return dp[0][0][2];
    }
};
