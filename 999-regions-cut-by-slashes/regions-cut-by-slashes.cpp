class Solution {
    vector<pair<int,int>> dir = {
        {-1, 0},  
        {1, 0},   
        {0, -1},  
        {0, 1}    
    };

    void helper(vector<vector<int>>& f, vector<vector<int>>& edges, int i, int j){
        int x = i * 3;
        int y = j * 3;
        
        int m = 0; int n = 0;

        for(int k = x; k < x + 3; k++){
            n = 0;
            for(int l = y; l < y + 3; l++){
                edges[k][l] = f[m][n];
                n++;
            }
            m++;
        }
    }

    void solve(vector<vector<int>>& vis, vector<vector<int>>& edges, int i, int j){
        int m = edges.size(); int n = edges[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();

            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nc < n && nr >= 0 && nc >= 0 && edges[nr][nc] != 1 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }

            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        unordered_map<char, vector<vector<int>>> mp;
        mp['/'] = {{0,0,1}, {0,1,0}, {1,0,0}};
        mp[' '] = {{0,0,0}, {0,0,0}, {0,0,0}};
        mp['\\'] = {{1,0,0}, {0,1,0}, {0,0,1}};

        int m = grid.size();
        int n = 0;
        for(int i = 0; i < grid[0].size(); ){
            if(grid[0][i] == '/' || grid[0][i] == ' '){
                i++;
            }
            else{
                i++;
            }
            n++;
        }
        m = m * 3;
        n = n * 3;
        vector<vector<int>> edges(m, vector<int>(n, 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                helper(mp[grid[i][j]], edges, i, j);
            }
        }

        int regions = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(edges[i][j] == 0 && !visited[i][j]){
                    solve(visited, edges, i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};