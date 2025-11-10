class Solution {
    int dp[205][205][205]; // dp[i][members][p]
    const int MOD = 1e9 + 7;

    int solve(int n, vector<int>& group, int i, int minProfit, vector<int>& profit, int p, int members) {
        if (i >= group.size()) {
            return p >= minProfit ? 1 : 0;
        }

        if (dp[i][members][p] != -1)
            return dp[i][members][p];

        int take = 0;
        if (members + group[i] <= n) {
            take = solve(n, group, i + 1, minProfit, profit, min(p + profit[i], minProfit), members + group[i]);
        }

        int notTake = solve(n, group, i + 1, minProfit, profit, p, members);

        return dp[i][members][p] = (take + notTake) % MOD;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(n, group, 0, minProfit, profit, 0, 0);
    }
};
