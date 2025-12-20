class Solution {
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, int k){
        if (i >= m || j >= n || k < 0) {
            return INT_MIN;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int score = grid[i][j];
        int cost  = (grid[i][j] == 0) ? 0 : 1;

        if (k - cost < 0) {
            return dp[i][j][k] = INT_MIN;
        }

        if (i == m - 1 && j == n - 1) {
            return dp[i][j][k] = grid[i][j];
        }

        int right = solve(i + 1, j, m, n, grid, k - cost);
        int down  = solve(i, j + 1, m, n, grid, k - cost);

        int best = INT_MIN;
        if (right != INT_MIN) best = max(best, score + right);
        if (down  != INT_MIN) best = max(best, score + down);

        return dp[i][j][k] = best;
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int ans = solve(0, 0, m, n, grid, k);
        return ans < 0 ? -1 : ans;
    }
};
