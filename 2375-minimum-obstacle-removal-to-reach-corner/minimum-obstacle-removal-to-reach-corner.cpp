typedef pair<int, pair<int, int>> P; //empty cell as 0 and obstacle one with 1, row, col

class Solution {
    int solve(int x, int y, int m, int n, vector<vector<int>>& grid){
        int count = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(m, vector<int>(n, 1e8));
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto t = pq.top(); pq.pop();
            int cost = t.first, r = t.second.first, c = t.second.second;
            if (cost > dist[r][c]) {
                continue;
            }
            if (r == m-1 && c == n-1) {
                return cost;
            }
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                    continue;
                }

                int newCost = cost + (grid[nr][nc] == 1 ? 1 : 0);

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
        return -1;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        return solve(0, 0, m, n, grid);
    }
};