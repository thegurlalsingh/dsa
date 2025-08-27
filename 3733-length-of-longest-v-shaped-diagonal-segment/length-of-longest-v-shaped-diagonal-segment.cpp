class Solution {
    int m, n;

    bool inside(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    pair<int,int> rotate90(int dx, int dy) {
        return {dy, -dx};
    }

private:
    int solve(int x, int y, int dx, int dy, vector<vector<int>>& grid, int k, int find) {
        if (!inside(x, y)) return 0;
        if (grid[x][y] != find) return 0;

        int len = 1;
        len = max(len, 1 + solve(x + dx, y + dy, dx, dy, grid, k, (find == 2 ? 0 : 2)));

        if (k > 0) {
            auto [ndx, ndy] = rotate90(dx, dy);
            len = max(len, 1 + solve(x + ndx, y + ndy, ndx, ndy, grid, k - 1, (find == 2 ? 0 : 2)));
        }
        return len;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int,int>> dirs = {{-1,-1},{-1,1},{1,-1},{1,1}};
                    for (auto [dx, dy] : dirs) {
                        count = max(count, 1 + solve(i + dx, j + dy, dx, dy, grid, 1, 2));
                    }
                }
            }
        }
        return count;
    }
};
