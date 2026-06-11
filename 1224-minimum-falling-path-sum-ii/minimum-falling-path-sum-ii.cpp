class Solution {
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(j < 0 || j >= n){
            return INT_MAX;
        } // i forgot this and redudantly mention ith index which will never be edge case

        if(i == m - 1){
            return matrix[i][j]; // redundant arguments like prevj or previ because when you reached last index just directly return that
        }
        
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = 0; k < n; k++){
            if(k != j){
                ans = min(ans, matrix[i][j] + solve(i + 1, k, matrix, dp));
            }
        }

        if(ans == INT_MAX){
            return dp[i][j] = INT_MAX;
        }

        return dp[i][j] = ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, grid, dp));
        }
        return ans;
    }
};