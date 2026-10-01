class Solution {
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j >= t.size()){
            return 1;
        }
        if(i >= s.size() && j < t.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int skip = solve(i + 1, j, s, t, dp);
        int take = 0;
        if(s[i] == t[j]){
            take = solve(i + 1, j + 1, s, t, dp); // match krgya toh aage badho bhai ruko mat, ruk tum skip se bhi jaoge
        }
        return dp[i][j] = take + skip;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t, dp);
    }
};