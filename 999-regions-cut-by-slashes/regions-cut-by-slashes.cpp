class Solution {
    void dfs(int i, int j, vector<vector<int>>& mat){
        int n = mat.size();
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat.size() || mat[i][j] == 1){
            return ;
        }

        mat[i][j] = 1;
        
        dfs(i + 1, j, mat);
        dfs(i, j + 1, mat);
        dfs(i - 1, j, mat);
        dfs(i, j - 1, mat);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(3 * n, vector<int>(3 * n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    mat[3 * i][3 * j + 2] = 1;
                    mat[3 * i + 1][3 * j + 1] = 1;
                    mat[3 * i + 2][3 * j] = 1;
                }
                else if(grid[i][j] == '\\'){
                    mat[3 * i][3 * j] = 1;
                    mat[3 * i + 1][3 * j + 1] = 1;
                    mat[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 3 * n; i++){
            for(int j = 0; j < 3 * n; j++){
                if(!mat[i][j]){
                    ans++;
                    dfs(i, j, mat);
                }
            }
        }
        return ans;
    }
};