class Solution {
    int helper(int i, int j, vector<string>& current, vector<vector<int>>& dp){
        if(i >= current.size() || j >= current[0].size() || i < 0 || j < 0 || current[i][j] == '#'){
            return 0;
        }
        if(i == current.size() - 1 && j == current[0].size() - 1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = helper(i, j + 1, current, dp);
        int down = helper(i + 1, j, current, dp);
        return dp[i][j] = right + down;
    }

    void solve(int x, int y, int m, int n, int k, vector<string>& ans, vector<string>& current, vector<vector<int>>& visited){
        
        for(int i = x; i < m; i++){

            int startY = (i == x ? y : 0);

            for(int j = startY; j < n; j++){
                
                if(visited[i][j]){
                    continue;
                }
                visited[i][j] = 1;
                current[i][j] = '#';
                vector<vector<int>> dp(m, vector<int>(n, -1));
                int paths = helper(0, 0, current, dp);
                if(paths == k){
                    ans = current;
                    return ;
                }
                if(paths == 0){
                    current[i][j] = '.';
                    visited[i][j] = 0;
                    continue;
                }
                solve(i, j + 1, m, n, k, ans, current, visited);
                // solve(i, j, m, n, k, ans, current, visited);
                current[i][j] = '.';
                visited[i][j] = 0;
            }
        }

        return ;
    }
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string> ans;
        vector<string> current;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                temp += ".";
            }
            current.push_back(temp);
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int paths = helper(0, 0, current, dp);
        if(paths == k){
            ans = current;
        }
        else{
            solve(0, 0, m, n, k, ans, current, visited);
        }
        return ans;
    }
};