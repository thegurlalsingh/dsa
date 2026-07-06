class Solution {
    bool can(vector<vector<int>>& dp, vector<vector<int>>& heights, int i, int j, int mid, vector<vector<int>>& vis){
        if(i == heights.size() - 1 && j == heights[0].size() - 1){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        vis[i][j] = 1;
        int up = 0, down = 0, right = 0, left = 0;
        if(i - 1 >= 0 && abs(heights[i][j] - heights[i - 1][j]) <= mid && !vis[i - 1][j]){
            up = can(dp, heights, i - 1, j, mid, vis);
        }
        if(j - 1 >= 0 && abs(heights[i][j] - heights[i][j - 1]) <= mid && !vis[i][j - 1]){
            left = can(dp, heights, i, j - 1, mid, vis);
        }
        if(i + 1 < heights.size() && abs(heights[i][j] - heights[i + 1][j]) <= mid && !vis[i + 1][j]){
            down = can(dp, heights, i + 1, j, mid, vis);
        }
        if(j + 1 < heights[0].size() && abs(heights[i][j] - heights[i][j + 1]) <= mid && !vis[i][j + 1]){
            right = can(dp, heights, i, j + 1, mid, vis);
        }
        return dp[i][j] = up || left || down || right;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(); int n = heights[0].size();
        int i = 0; int j = 1e9;
        int ans = -1;
        while(i <= j){
            vector<vector<int>> dp(m, vector<int>(n, -1));
            vector<vector<int>> vis(m, vector<int>(n, 0));
            int mid = (i + j) / 2; // this mid is that maximum abs diff which we are minimizing
            if(can(dp, heights, 0, 0, mid, vis)){
                ans = mid;
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};