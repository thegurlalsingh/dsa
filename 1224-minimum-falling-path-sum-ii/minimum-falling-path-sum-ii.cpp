class Solution {
public:
    int shortest_path(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        if (r < 0 || r >= n || c < 0 || c >= n) return 1e9; // Out of bounds
        if (dp[r][c] != INT_MIN) return dp[r][c]; // Memoized result
        if (r == n - 1) return dp[r][c] = grid[r][c]; // Base case

        int nc = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i == c) continue; // Skip same column
            nc = min(nc, shortest_path(r + 1, i, grid, dp));
        }

        dp[r][c] = grid[r][c] + nc;
        return dp[r][c];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        for (int i = 0; i < n; i++) {
            ans = min(ans, shortest_path(0, i, matrix, dp));
        }
        return ans;
    }
};