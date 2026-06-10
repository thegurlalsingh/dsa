class Solution {
    int solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp) {
        if (i >= s1.size() && j >= s2.size() && k >= s3.size()) {
            return true;
        }

        // if(i >= s1.size() || j >= s2.size()){
        //     return false;
        // }

        if (i == s1.size()) {
            return s2.substr(j) == s3.substr(k);
        }

        if (j == s2.size()) {
            return s1.substr(i) == s3.substr(k);
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        bool ans = false;
        if (s1[i] == s3[k]) {
            ans = solve(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        if (s2[j] == s3[k]) {
            ans |= solve(i, j + 1, k + 1, s1, s2, s3, dp);
        }

        return dp[i][j][k] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if ((s1.size() == 0 && (s2 == s3)) || (s2.size() == 0 && (s1 == s3)) ||
            (s1 == s2 && s2 == s3)) {
            return true;
        }
        vector<vector<vector<int>>> dp(s1.size(), vector<vector<int>>(s2.size(), vector<int>(s3.size(), -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};