class Solution {
    int solve(int i, int prev, vector<vector<int>>& grid, int limit, vector<vector<int>>& dp){
        if(i >= grid[0].size()){
            return 0;
        }
        if(dp[i][prev + 1] != -1){
            return dp[i][prev + 1];
        }
        bool t = true;
        int ans = INT_MAX;
    
        for(int j = 0; j < grid.size(); j++){
            if(prev != -1 && abs(grid[j][i] - grid[j][prev]) > limit){
                t = false;
                break;
            }
        }
        if(prev == -1 || t){
            int temp = solve(i + 1, i, grid, limit, dp);
            if(temp != INT_MAX){
                ans = min(ans, temp);
            }  
        }
        int temp = solve(i + 1, prev, grid, limit, dp);
        if(temp != INT_MAX){
            ans = min(ans, 1 + temp);
        }
        return dp[i][prev + 1] = ans;
    }
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        vector<vector<int>> dp(grid[0].size(), vector<int>(grid[0].size() + 1, -1));
        return grid[0].size() - solve(0, -1, grid, limit, dp); // solve will find minimum removals
    }
};