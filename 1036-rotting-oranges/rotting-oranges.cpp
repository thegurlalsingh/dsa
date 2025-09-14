class Solution {
public:
    struct Node {
        int r, c, t;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<Node> q;
        int fresh = 0;

        // 1. Add rotten oranges & count fresh
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};
        int maxTime = 0, rotten = 0;

        // 2. BFS
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            maxTime = max(maxTime, curr.t);

            for(int k=0;k<4;k++){
                int nr = curr.r + dRow[k];
                int nc = curr.c + dCol[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr,nc,curr.t+1});
                    rotten++;
                }
            }
        }

        // 3. Check if all fresh rotted
        return rotten == fresh ? maxTime : -1;
    }
};