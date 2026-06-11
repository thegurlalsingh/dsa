class Solution {
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if(i >= m || j >= n || i < 0 || j < 0){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = 0; int down = 0;
        if(i + 1 < m && obstacleGrid[i + 1][j] != 1){
            right = solve(i + 1, j, m, n, dp, obstacleGrid); 
        }
        if(j + 1 < n && obstacleGrid[i][j + 1] != 1){
            down = solve(i, j + 1, m, n, dp, obstacleGrid); 
        }
        return dp[i][j] = right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp, obstacleGrid);
    }
};