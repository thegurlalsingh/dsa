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
        return dp[i][j] = ans;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        return solve(0, 0, triangle, dp);
    }
};