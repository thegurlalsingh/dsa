class Solution {
    bool isValid(int r, int c, int m, int n){
        return r >= 0 && c >= 0 && r < m && c < n;
    }

    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); int n = heights[0].size();
        unordered_set<pair<int, int>, PairHash> pacific, atlantic;
        vector<vector<int>> visited1(m, vector<int>(n, 0));
        vector<vector<int>> visited2(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            pacific.insert({0, i}); // top -> pacific
            visited1[0][i] = 1;
        }
        for(int i = 0; i < n; i++){
            atlantic.insert({m - 1, i}); // bottom -> atlantic
            visited2[m - 1][i] = 1;
        }
        for(int i = 0; i < m; i++){
            pacific.insert({i, 0}); // left -> pacific
            visited1[i][0] = 1;
        }
        for(int i = 0; i < m; i++){
            atlantic.insert({i, n - 1}); // right -> atlantic
            visited2[i][n - 1] = 1;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        for(auto p : pacific){
            q.push(p); // multi source bfs
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(isValid(nr, nc, m, n) && !visited1[nr][nc] && (heights[nr][nc] >= heights[r][c])){
                    q.push({nr, nc});
                    visited1[nr][nc] = 1;
                    pacific.insert({nr, nc});
                }
            }
        }

        for(auto p : atlantic){
            q.push(p); // multi source bfs
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(isValid(nr, nc, m, n) && !visited2[nr][nc] && (heights[nr][nc] >= heights[r][c])){
                    q.push({nr, nc});
                    visited2[nr][nc] = 1;
                    atlantic.insert({nr, nc});
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto& p : pacific){
            if(atlantic.find(p) != atlantic.end()){
                ans.push_back({p.first, p.second});
            }
        }

        return ans;
    }
};