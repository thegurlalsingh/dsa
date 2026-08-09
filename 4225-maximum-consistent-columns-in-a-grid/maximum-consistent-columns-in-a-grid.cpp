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
        } // checking if this col satisfies the condition
        if(prev == -1 || t){
            int temp = solve(i + 1, i, grid, limit, dp);
            if(temp != INT_MAX){
                ans = min(ans, temp);
            }  
        } // if you havent chose anything in prev and this col satisfies the condtion, you can keep it (we are not doing +1 because solve gives minimum removals but this part of code is for remaining col because they satisfied condition)
        int temp = solve(i + 1, prev, grid, limit, dp);
        if(temp != INT_MAX){
            ans = min(ans, 1 + temp);
        } // if they are valid or not does not matter, you can still remove them and have a better solution in future so yes, i + 1 means go ahead and skip current and keep prev as prev and +1 because this is removal
        return dp[i][prev + 1] = ans;
    }
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        vector<vector<int>> dp(grid[0].size(), vector<int>(grid[0].size() + 1, -1));
        return grid[0].size() - solve(0, -1, grid, limit, dp); // solve will find minimum removals to make to maximize the ans
    }
};