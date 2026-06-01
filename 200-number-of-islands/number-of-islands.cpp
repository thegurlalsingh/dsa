class Solution {
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    int m; int n;

    void solve(vector<vector<int>>& visited, int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if(visited[t.first][t.second]){
                continue;
            }
            visited[t.first][t.second] = 1;
            for (int k = 0; k < 4; k++) {
                int nr = t.first + dr[k];
                int nc = t.second + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && (grid[nr][nc] == '1')) {
                    q.push({nr, nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    solve(visited, i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};