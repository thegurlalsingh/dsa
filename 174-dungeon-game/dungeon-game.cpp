class Solution {
    bool solve(int i, int j, int e, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        if(i >= dungeon.size() || j >= dungeon[0].size() || e <= 0) {
            return false;
        }
        e += dungeon[i][j];
        if(e <= 0) {
            return false;
        }
        if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            return true;
        }
        if(dp[i][j] >= e) { // dp[i][j] = maximum health remaining when reaching (i,j) Then if another path reaches the same cell with less health, we don't need it.
            return false;
        }
        dp[i][j] = e; 
        int right = solve(i, j + 1, e, dungeon, dp);
        int down = solve(i + 1, j, e, dungeon, dp);

        return right || down;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(); int n = dungeon[0].size();
        int low = 0; int high = 1e4;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            vector<vector<int>> dp(m, vector<int>(n, -1)); // we cant memoize it by bool data structure because then we also have to keep initial energy in dp and that will be huge..... so instead of answering have I already solved this cell, the maximum amount of health with which we have already reached cell (i,j) during the current mid feasibility check.
            if(solve(0, 0, mid, dungeon, dp)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};