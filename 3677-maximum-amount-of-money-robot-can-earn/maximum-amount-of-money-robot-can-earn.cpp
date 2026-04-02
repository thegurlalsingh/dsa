class Solution {
    int solve(int sx, int sy, int ex, int ey,
              vector<vector<vector<int>>>& dp,
              vector<vector<int>>& coins, int k){

        if(sx > ex || sy > ey) return INT_MIN;

        if(sx == ex && sy == ey){
            if(coins[sx][sy] < 0){
                if(k > 0) return 0; 
                else return coins[sx][sy];
            }
            return coins[sx][sy];
        }

        if(dp[sx][sy][k] != INT_MIN){
            return dp[sx][sy][k];
        }

        int ans = INT_MIN;

        int val = coins[sx][sy];
        int right = solve(sx, sy + 1, ex, ey, dp, coins, k);
        int down  = solve(sx + 1, sy, ex, ey, dp, coins, k);

        int best = max(right, down);
        if(best != INT_MIN){
            ans = max(ans, val + best);
        }

        if(coins[sx][sy] < 0 && k > 0){
            int right2 = solve(sx, sy + 1, ex, ey, dp, coins, k - 1);
            int down2  = solve(sx + 1, sy, ex, ey, dp, coins, k - 1);

            int best2 = max(right2, down2);
            if(best2 != INT_MIN){
                ans = max(ans, best2); 
            }
        }

        return dp[sx][sy][k] = ans;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(); 
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        return solve(0, 0, m - 1, n - 1, dp, coins, 2);
    }
};