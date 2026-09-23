class Solution {
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == triangle.size() - 1 && j == triangle[0].size() - 1){
            return triangle[triangle.size() - 1][triangle[0].size() - 1];
        }
        // if(i >= triangle.size() || j >= triangle[0].size()){
        //     return 0;
        // }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = INT_MAX; int down = INT_MAX;
        if(j + 1 < triangle[0].size()){
            right = triangle[i][j] + solve(i, j + 1, triangle, dp);
        }
        if(i + 1 < triangle.size()){
            down = triangle[i][j] + solve(i + 1, j, triangle, dp);
        }
        return dp[i][j] = min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(0, 0, grid, dp);
    }
};