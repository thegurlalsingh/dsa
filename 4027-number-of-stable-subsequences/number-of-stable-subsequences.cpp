const int MOD = 1e9 + 7;

class Solution {
    int dp[100005][3][3];   
    
    int solve(int i, vector<int>& nums, int prev1, int prev2){
        if(i >= nums.size()){
            return 1;
        }

        int p1 = (prev1 == -1 ? 2 : prev1);
        int p2 = (prev2 == -1 ? 2 : prev2);

        if(dp[i][p1][p2] != -1)
            return dp[i][p1][p2];

        int skip = solve(i + 1, nums, prev1, prev2) ;

        int currParity = nums[i] % 2;
        int take = 0;

        if(currParity != prev1 || currParity != prev2){
            take = solve(i + 1, nums, currParity, prev1);
        }

        return dp[i][p1][p2] = (skip + take) % MOD;
    }

public:
    int countStableSubsequences(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, -1, -1) - 1;
    }
};