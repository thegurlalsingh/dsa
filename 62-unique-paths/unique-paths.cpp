class Solution {
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1; // reached destination
        }
        if (i >= m || j >= n) {
            return 0; // out of bounds
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j]; // already computed
        }

        int right = solve(i + 1, j, m, n, dp);
        int down = solve(i, j + 1, m, n, dp);

        return dp[i][j] = right + down;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};
