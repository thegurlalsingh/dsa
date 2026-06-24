class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});

                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        int time = -1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [row, column] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = row + dx[k];
                    int nj = column + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < grid.size() &&
                        nj < grid[0].size() && visited[ni][nj] == -1) {
                        if (grid[ni][nj] == 1) {
                            fresh--;
                            q.push({ni, nj});
                            visited[ni][nj] = 1;
                        }
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? max(0, time) : -1;
    }
};