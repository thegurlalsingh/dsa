class Solution {
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp){
        if(i >= s1.size() && j >= s2.size() && k >= s3.size()){
            return true;
        }
        if(k >= s3.size()){
            return false;
        } // this base case instead of i >= s1.size() || j >= s2.size() || k >= s3.size() because there can be a case were i ended but j and k are remaining and they would match so just taking care of k that it should not be outside of boundaries 
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        bool way1 = false; 
        bool way2 = false;
        if(s1[i] == s3[k]){
            way1 |= solve(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        if(s2[j] == s3[k]){
            way2 |= solve(i, j + 1, k + 1, s1, s2, s3, dp);
        }
        return dp[i][j][k] = way1 || way2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1))); // using int in dp instead of false because false will have two meanings, not calculated and answer is not true thats why using -1 as not calculated and then false will do its work
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};