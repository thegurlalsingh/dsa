class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> res(m, vector<int>(n, -1)); 
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d];
                int ny = y + dirs[d + 1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && res[nx][ny] == -1) {
                    res[nx][ny] = res[x][y] + 1; 
                    q.push({nx, ny});
                }
            }
        }
        
        return res;
    }
};
