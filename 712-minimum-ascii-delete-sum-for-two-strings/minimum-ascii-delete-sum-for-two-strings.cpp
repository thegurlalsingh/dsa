class Solution {
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>>& dp){
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int take = 0;
        if(text1[i] == text2[j]){
            take = (int)text1[i] + solve(i + 1, j + 1, text1, text2, dp);
        }
        int skip = max(solve(i + 1, j, text1, text2, dp), solve(i, j + 1, text1, text2, dp));
        

        return dp[i][j] = max(take, skip);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        if(s1.size() > s2.size()){
            swap(s2, s1);     // word1 should be bigger than word2
        }
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        int ans = solve(0, 0, s1, s2, dp);
        int ascii_s1 = 0;
        int ascii_s2 = 0;
        for(int i = 0; i < s1.size(); i++){
            ascii_s1 += (int)s1[i];
        }
        for(int i = 0; i < s2.size(); i++){
            ascii_s2 += (int)s2[i];
        }
        return ascii_s1 + ascii_s2 - 2 * ans;
    }
};