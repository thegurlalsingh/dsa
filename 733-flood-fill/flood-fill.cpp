class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); int n = image[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> ans = image;
        vis[sr][sc] = 1;
        int source = image[sr][sc];
        ans[sr][sc] = color;
        q.push({sr, sc});
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == source && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    ans[nr][nc] = color;
                    q.push({nr, nc});
                    
                }
            }
        }

        return ans;
    }
};