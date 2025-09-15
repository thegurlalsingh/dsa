class Solution {
public:
    
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
    }
    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(auto [nr , nc] : dir){
            int row = nr + r ;
            int col = nc + c;
            if(row>=0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] == 1){
                vis[row][col] = 1;
                q.push({row,col});
            }
        }

    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j] && grid[i][j]==1)ans++;
        }
    }
    return ans;






}
};