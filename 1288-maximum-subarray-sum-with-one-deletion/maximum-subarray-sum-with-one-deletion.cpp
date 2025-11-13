class Solution {
    int solve(int i, bool deleted, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == arr.size()) return INT_MIN; // end of array
        if (dp[i][deleted] != INT_MIN) return dp[i][deleted];

        int take = arr[i]; // start new subarray
        int extend = INT_MIN;

        int next = solve(i + 1, deleted, arr, dp);
        if (next != INT_MIN) extend = arr[i] + next; // only add if safe

        int res = max(take, extend);

        // delete current element if not yet deleted
        if (!deleted) {
            res = max(res, solve(i + 1, true, arr, dp));
        }

        return dp[i][deleted] = res;
    }

public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, false, arr, dp));
        }
        return ans;
    }
};
