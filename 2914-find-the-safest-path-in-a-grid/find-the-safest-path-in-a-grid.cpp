int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
    int manhattan(int x1, int x2, int y1, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    bool solve(int mid, vector<vector<int>>& dist) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(dist.size(),
                                 vector<bool>(dist[0].size(), false));
        q.push({0, 0});
        if (dist[0][0] < mid) {
            return false;
        }
        vis[0][0] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            // if (dist[t.first][t.second] <= mid) {
            //     return false;
            // }
            if (t.first == dist.size() - 1 && t.second == dist[0].size() - 1) {
                return true;
            }
            for (int k = 0; k < 4; k++) {
                int nr = t.first + dx[k];
                int nc = t.second + dy[k];

                if (nr >= 0 && nr < dist.size() && nc >= 0 &&
                    nc < dist[0].size()) {
                    if (dist[nr][nc] >= mid && !vis[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    }
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [row, col, dis] = q.front();
            q.pop();
            
            if (dis > dist[row][col]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nr = row + dx[k];
                int nc = col + dy[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int d = dis + manhattan(row, nr, col, nc);
                    if (d < dist[nr][nc]) {
                        dist[nr][nc] = d;
                        q.push({nr, nc, d});
                    }
                }
            }
        }

        int i = 0;
        int j = 1e9;
        int ans = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (solve(mid, dist)) {
                i = mid + 1; // maximizing here this time because dist
                             // contains minimum dist already
                ans = mid;
            } else {
                j = mid - 1;
            }
        }

        return ans;
    }
};