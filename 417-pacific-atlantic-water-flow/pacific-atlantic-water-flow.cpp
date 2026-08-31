class Solution {
    vector<pair<int, int>> directions = {
        {-1, 0}, 
        {0, 1},  
        {1, 0},  
        {0, -1}  
    };

    void solve(queue<pair<int, int>> q, vector<vector<int>>& vis, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
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

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && (heights[nr][nc] >= heights[r][c])) {
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacificvis(m, vector<int>(n, 0));
        vector<vector<int>> atlanticvis(m, vector<int>(n, 0));
        queue<pair<int, int>> pacificq, atlanticq;

        for (int i = 0; i < m; i++) {
            pacificq.push({i, 0});
        }
        for (int i = 0; i < m; i++) {
            atlanticq.push({i, n - 1});
        }
        for (int i = 0; i < n; i++) {
            pacificq.push({0, i});
        }
        for (int i = 0; i < n; i++) {
            atlanticq.push({m - 1, i});
        }

        solve(pacificq, pacificvis, heights);
        solve(atlanticq, atlanticvis, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificvis[i][j] && atlanticvis[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};