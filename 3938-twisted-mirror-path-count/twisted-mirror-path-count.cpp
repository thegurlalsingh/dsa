class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        queue<pair<int, int>> q;
        vector<vector<int>> ways(m, vector<int>(n, 0));
        ways[0][0] = 1;
        // vector<vector<int>> visited(m, vector<int>(n, 0));

        // 0 mean left to right
        // 1 mean up to down
        vector<vector<pair<int, int>>> pre_right(
            m, vector<pair<int, int>>(n, {-1, -1})); //  {row, col, 0}
        vector<vector<pair<int, int>>> pre_down(
            m, vector<pair<int, int>>(n, {-1, -1})); //  {row, col, 1}

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // if cell hits it from left to right
                    int y = i;
                    int z = j;
                    int dir = 0;
                    while (y < m && z < n && grid[y][z] == 1) {
                        if (dir == 0) {
                            dir = 1;
                            y++;
                        } else {
                            dir = 0;
                            z++;
                        }
                    }
                    if (y < m && z < n && grid[y][z] != 1) {
                        pre_right[i][j] = {y, z};
                    } else {
                        pre_right[i][j] = {-1, -1};
                    }

                    // if cell hits it from up to down
                    y = i;
                    z = j;
                    dir = 1;
                    while (y < m && z < n && grid[y][z] == 1) {
                        if (dir == 0) {
                            dir = 1;
                            y++;
                        } else {
                            dir = 0;
                            z++;
                        }
                    }
                    if (y < m && z < n && grid[y][z] != 1) {
                        pre_down[i][j] = {y, z};
                    } else {
                        pre_down[i][j] = {-1, -1};
                    }
                }
            }
        }

        const int MOD = 1e9 + 7;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (ways[r][c] == 0)
                    continue;

                // RIGHT
                if (c + 1 < n) {
                    if (grid[r][c + 1] == 1) {
                        auto [y, z] = pre_right[r][c + 1];

                        if (y != -1) {
                            ways[y][z] = (ways[y][z] + ways[r][c]) % MOD;
                        }
                    } else {
                        ways[r][c + 1] = (ways[r][c + 1] + ways[r][c]) % MOD;
                    }
                }

                // DOWN
                if (r + 1 < m) {
                    if (grid[r + 1][c] == 1) {
                        auto [y, z] = pre_down[r + 1][c];

                        if (y != -1) {
                            ways[y][z] = (ways[y][z] + ways[r][c]) % MOD;
                        }
                    } else {
                        ways[r + 1][c] = (ways[r + 1][c] + ways[r][c]) % MOD;
                    }
                }
            }
        }

        return ways[m - 1][n - 1];
    }
};