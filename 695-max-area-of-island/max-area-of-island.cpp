class Solution {
    vector<pair<int, int>> directions = {
        {-1, 0}, 
        {0, 1},  
        {1, 0},  
        {0, -1}  
    };

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y){
        int temp = 0;
        int m = grid.size(); int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            if(vis[r][c]){
                continue;
            }
            vis[r][c] = 1;
            temp++;
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && (grid[nr][nc] == 1)) {
                    q.push({nr, nc});
                }
            }
        }
        return temp;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c = INT_MIN;
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int count = bfs(grid, vis, i, j);
                    c = max(count, c);
                }
            }
        }
        return c  == INT_MIN ? 0 : c;
    }
};