class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i+1][j-1]))
                    isPal[i][j] = true;
            }
        }

        vector<int> dp(n + 1, -1);
        return solve(0, s, isPal, dp) - 1;
    }

    int solve(int i, string &s, vector<vector<bool>>& isPal, vector<int>& dp) {
        int n = s.size();
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < n; j++) {
            if (isPal[i][j]) {
                ans = min(ans, 1 + solve(j + 1, s, isPal, dp));
            }
        }

        return dp[i] = ans;
    }
};
