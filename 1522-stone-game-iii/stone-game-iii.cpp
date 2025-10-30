class Solution {
public:

    int solveMem(vector<int>& stoneValue, int i, vector<int>&dp) {
        if (i == stoneValue.size())
            return 0;
        if(dp[i]!=INT_MIN)
            return dp[i];
        int ans = INT_MIN;
        ans = max(ans, stoneValue[i] - solveMem(stoneValue, i + 1,dp));
        if (i + 1 < stoneValue.size())
            ans = max(ans, stoneValue[i] + stoneValue[i + 1] - solveMem(stoneValue, i + 2,dp));
        if (i + 2 < stoneValue.size())
            ans = max(ans, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solveMem(stoneValue, i + 3,dp));
        return dp[i] = ans;
    }
 
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,INT_MIN);
        int ans = solveMem(stoneValue, 0,dp);
        if (ans > 0)
            return "Alice";
        else if (ans < 0)
            return "Bob";
        return "Tie";
    }
};