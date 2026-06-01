class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // bool freshPresent = false;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(grid[i][j] == 1){
        //             freshPresent = true;
        //         }
        //     }
        // }
        // if(!freshPresent){
        //     return 0;
        // }

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int minutes = 0;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = t.first + dr[k];
                int nc = t.second + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 2 && grid[nr][nc] != 0 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[t.first][t.second] + 1;
                    q.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dist[i][j] != -1 && dist[i][j] != 0){
                    minutes = max(minutes, dist[i][j]);
                }
            }
        }

        bool allRotten = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && dist[i][j] == -1){
                    allRotten = false;
                }
            }
        }

        if(allRotten){
            return minutes == INT_MAX ? -1 : minutes;
        }
        return -1;
    }
};