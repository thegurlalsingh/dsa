class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i >= days.size()) return 0;      // base case
        if (dp[i] != -1) return dp[i];       // memo check

        // Option 1: 1-day pass
        int cost1 = costs[0] + solve(i + 1, days, costs, dp);

        // Option 2: 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++;
        int cost2 = costs[1] + solve(j, days, costs, dp);

        // Option 3: 30-day pass
        int k = i;
        while (k < days.size() && days[k] < days[i] + 30) k++;
        int cost3 = costs[2] + solve(k, days, costs, dp);

        return dp[i] = min({cost1, cost2, cost3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, days, costs, dp);
    }
};
