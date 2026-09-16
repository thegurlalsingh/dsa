class Solution {
    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int skip1 = solve(i + 1, j, text1, text2, dp);
        int skip2 = solve(i, j + 1, text1, text2, dp);
        int take = 0;
        if(text1[i] == text2[j]){
            take = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }
        int ans = max(skip1, skip2);
        ans = max(ans, take);
        return dp[i][j] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return solve(0, 0, text1, text2, dp);
    }
};