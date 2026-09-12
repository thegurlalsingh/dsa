typedef tuple<int, int, int> T;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        vector<vector<int>> dir = {
            {0, 1},  // right
            {0, -1}, // left
            {1, 0},  // down
            {-1, 0}  // up
        };

        while (!pq.empty()) {
            auto [c, r, col] = pq.top();
            pq.pop();

            if (c > dist[r][col]){
                continue;
            }

            if (r == m - 1 && col == n - 1) {
                return c;
            }

            for (int k = 0; k < 4; k++) {

                int i = r + dir[k][0];
                int j = col + dir[k][1];

                int newCost = c;

                if (i < m && j < n && i >= 0 && j >= 0) {
                    if (k + 1 != grid[r][col]) {
                        newCost++;
                    }

                    if (newCost < dist[i][j]) {
                        dist[i][j] = newCost;
                        pq.push({newCost, i, j});
                    }
                }
            }
        }

        return -1;
    }
};