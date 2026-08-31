class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (vis[r][c]) {
                continue;
            }
            vis[r][c] = 1;
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    count++;
                } // if new cell is a boundary cell
                else if (grid[nr][nc] == 0) {
                    count++;
                } // if it is a water cell
                else if (grid[nr][nc] == 1) {
                    q.push({nr, nc});
                } // if it is land -> push into queue again
            }
        }
        return count;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int x = 0;
        int y = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int peri = bfs(x, y, grid, vis);
        return peri;
    }
};