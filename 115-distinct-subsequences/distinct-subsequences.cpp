class Solution {
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == t.size() - 1) { 
            int ans = 0;
            for (int k = i; k < s.size(); k++) {
                if (s[k] == t[j]) {
                    ans++; // there are cases where last char of t can match with multiple ending chars of s, so counting all of them and returning
                }
            }
            return ans;
        }
        if (i >= s.size()) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int skip = solve(i + 1, j, s, t, dp);
        int take = 0;
        if (s[i] == t[j]) {
            take = solve(i + 1, j + 1, s, t, dp);
        }
        return dp[i][j] = take + skip;
    }

public:
    int numDistinct(string s, string t) { 
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t, dp); 
    }
};