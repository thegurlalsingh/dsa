class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

public:
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_set<pair<int, int>, PairHash> s;
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    s.insert({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    (grid[nr][nc] == 1) && !vis[nr][nc]) {
                    s.erase({nr, nc});
                    vis[nr][nc] = 1;
                    if (s.empty()) { // Check the condition at the exact point where the state you're tracking changes. Thats why we moved it from up to down
                        return t + 1;
                    }
                    q.push({nr, nc, t + 1});
                }
            }
        }

        return s.empty() ? 0 : -1;
    }
};