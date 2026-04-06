typedef tuple<int, int, int> P;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        int dx[4] = {-1, 0, 1, 0}; 
        int dy[4] = {0, 1, 0, -1};

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [time, x, y] = pq.top(); 
            pq.pop();

            if (x == m - 1 && y == n - 1) return time;

            if (time > dist[x][y]) continue;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newTime = max(time, grid[nx][ny]);

                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};