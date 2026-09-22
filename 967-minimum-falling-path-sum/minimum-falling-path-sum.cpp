class Solution {
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i >= triangle.size()){
            return 0;
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        int ans = INT_MAX;
        ans = min(ans, triangle[i][j] + solve(i + 1, j, triangle, dp));
        if(j + 1 < triangle[i].size()){
            ans = min(ans, triangle[i][j + 1] + solve(i + 1, j + 1, triangle, dp));
        }
        if(j - 1 < triangle[i].size()){
            ans = min(ans, triangle[i][j - 1] + solve(i + 1, j - 1, triangle, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), INT_MAX));
        int k = INT_MAX;
        for(int i = 0; i < matrix[0].size(); i++){
            k = min(k, solve(0, i, matrix, dp));
        }
        return k;
    }
};