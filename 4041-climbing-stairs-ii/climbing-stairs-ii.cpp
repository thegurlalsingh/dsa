class Solution {
    int solve(int i, vector<int>& costs, vector<int>& dp) {
        if (i >= costs.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MAX;
        if (i < costs.size()) {
            int one = costs[i] + 1 + solve(i + 1, costs, dp);
            ans = min(one, ans);
        }
        if (i + 1 < costs.size()) {
            int two = costs[i + 1] + 4 + solve(i + 2, costs, dp);
            ans = min(two, ans);
        }
        if (i + 2 < costs.size()) {
            int three = costs[i + 2] + 9 + solve(i + 3, costs, dp);
            ans = min(three, ans);
        }
        return dp[i] = ans;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, -1);
        return solve(0, costs, dp);
    }
};