class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> pacific, atlantic;
        vector<vector<int>> visp(m, vector<int>(n, -1));
        vector<vector<int>> visa(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            pacific.push({i, 0});
            visp[i][0] = 1;

        } // right
        for (int i = 0; i < n; i++) {
            pacific.push({0, i});
            visp[0][i] = 1;

        } // top
        for (int i = 0; i < n; i++) {
            atlantic.push({m - 1, i});
            visa[m - 1][i] = 1;

        } // bottom
        for (int i = 0; i < m; i++) {
            atlantic.push({i, n - 1});
            visa[i][n - 1] = 1;

        } // left

        

        vector<vector<int>> ans;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!pacific.empty()) {

            auto [r, c] = pacific.front();
            pacific.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    heights[nr][nc] >= heights[r][c] && visp[nr][nc] == -1) {
                    visp[nr][nc] = 1;
                    pacific.push({nr, nc});
                }
            }
        }

        while (!atlantic.empty()) {

            auto [r, c] = atlantic.front();
            atlantic.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    heights[nr][nc] >= heights[r][c] && visa[nr][nc] == -1) {
                    visa[nr][nc] = 1;
                    atlantic.push({nr, nc});
                }
            }
        }


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visp[i][j] != -1 && visa[i][j] != -1){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};