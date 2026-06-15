class Solution {
    int solve(int i, int j,
              vector<vector<int>>& dungeon,
              vector<vector<int>>& dp) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        if(i >= m || j >= n)
            return INT_MAX;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == m-1 && j == n-1)
            return max(1, 1 - dungeon[i][j]);

        int down = solve(i+1, j, dungeon, dp);
        int right = solve(i, j+1, dungeon, dp);

        int need = min(down, right) - dungeon[i][j];

        return dp[i][j] = max(1, need);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        return solve(0, 0, dungeon, dp);
    }
};