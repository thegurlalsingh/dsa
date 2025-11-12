class Solution {
    int helper(string& temp, int check){
        if(check == 0){
            int zeros = 0;
            for(char c : temp) if(c == '0') zeros++;
            return zeros;
        } else {
            int ones = 0;
            for(char c : temp) if(c == '1') ones++;
            return ones;
        }
    }

    int solve(int i, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        if(i == strs.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        // Skip current string
        int skip = solve(i + 1, strs, m, n, dp);

        // Take current string if possible
        int take = 0;
        int t0 = helper(strs[i], 0);
        int t1 = helper(strs[i], 1);
        if(t0 <= m && t1 <= n){
            take = 1 + solve(i + 1, strs, m - t0, n - t1, dp);
        }

        return dp[i][m][n] = max(take, skip);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        // Initialize dp with -1
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, strs, m, n, dp);
    }
};
