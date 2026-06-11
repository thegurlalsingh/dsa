class Solution {
    int solve(int i, int j, vector<vector<char>>& matrix,
              vector<vector<int>>& dp, int& ans) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, matrix, dp, ans);
        int down = solve(i + 1, j, matrix, dp, ans);
        int diag = solve(i + 1, j + 1, matrix, dp, ans);

        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min({right, down, diag});
            ans = max(ans, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        solve(0, 0, matrix, dp, ans);
        return ans * ans;
    }
};