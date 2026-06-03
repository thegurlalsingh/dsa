typedef pair<pair<int, int>, int> P;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

struct comp {
    bool operator()(const P& a, const P& b) {
        return a.second > b.second; // min heap on effort
    }
};

class Solution {
    int dijkstra(vector<vector<int>>& matrix) {
        priority_queue<P, vector<P>, comp> pq;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        dist[0][0] = matrix[0][0];
        pq.push({{0, 0}, matrix[0][0]}); // remember as we are pruning early, we are returning total minimum time so push that only, not single cell weight

        while (!pq.empty()) {

            auto t = pq.top();
            int x = t.first.first, y = t.first.second, time = t.second;
            pq.pop();

            if (x == m - 1 && y == n - 1) {
                return time;
            }

            if (time > dist[x][y])
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int new_time = max(time, matrix[nx][ny]);
                
                    if (new_time < dist[nx][ny]) {
                        dist[nx][ny] = new_time;
                        pq.push({{nx, ny}, new_time});
                    }
                }
            }
        }

        return -1;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};