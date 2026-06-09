class Solution {
    pair<int, int> helper(string &s){
        int ones = 0, zeros = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                zeros++;
            }
            else{
                ones++;
            }
        }
        return {zeros, ones};
    }

    int solve(int i, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        if(i >= strs.size()){
            return 0;
        }

        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }

        auto t = helper(strs[i]);
        int skip = solve(i + 1, strs, m, n, dp);
        int take = INT_MIN;
        if(t.first <= m && t.second <= n){
            take = 1 + solve(i + 1, strs, m - t.first, n - t.second, dp);
        }

        return dp[i][m][n] = max(skip, take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0, strs, m, n, dp);
    }
};