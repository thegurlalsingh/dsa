class Solution {
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(j < 0 || j >= n){
            return INT_MAX;
        }

        if(i == m - 1){
            return matrix[i][j];
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        int downLeft = solve(i + 1, j - 1, matrix, dp);
        int down = solve(i + 1, j, matrix, dp);
        int downRight = solve(i + 1, j + 1, matrix, dp);

        int best = min({downLeft, down, downRight});

        if(best == INT_MAX){
            return dp[i][j] = INT_MAX;
        }

        return dp[i][j] = matrix[i][j] + best;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix, dp));
        }
        return ans;
    }
};