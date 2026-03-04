class Solution {
    const int MOD = 1e9 + 7;
    int dp[501][501][2];   
    
    int solve(int i, int j, vector<vector<int>>& grid, bool dir){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0){
            return 0;
        }
        
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return 1;
        }
        
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        
        int ans = 0;
        
        if(grid[i][j] == 1){
            if(dir == false){
                ans = solve(i, j + 1, grid, true);
            }
            else{
                ans = solve(i + 1, j, grid, false);
            }
        }
        else{
            ans += solve(i + 1, j, grid, false) % MOD;
            ans += solve(i, j + 1, grid, true) % MOD;
        }

        return dp[i][j][dir] = ans % MOD;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, grid, false); 
    }
};