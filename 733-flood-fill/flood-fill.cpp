class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); int n = image[0].size();
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        vector<vector<int>> ne = image;
        queue<tuple<int, int, int>> q;
        int inc = ne[sr][sc];
        q.push({sr, sc, inc});
        if(inc == color){
            return ne;
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            // if(get<2>(t) == color){
            //     continue;
            // }
            ne[get<0>(t)][get<1>(t)] = color;
            for (int k = 0; k < 4; k++) {
                int nr = get<0>(t) + dr[k];
                int nc = get<1>(t) + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(ne[nr][nc] == inc){
                        ne[nr][nc] = color;
                        q.push({nr, nc, inc});
                    }
                    
                }
                // q.push({nr, nc, color});
            }
        }
        return ne;
    }
};