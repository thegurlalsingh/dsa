class Solution {
    int solve(int j, vector<int> &dp, string& s) {
        if (j >= s.size()) {
            return 1;
        }
        if(dp[j] != -1){
            return dp[j];
        }
        int ans = 0;
        if (s[j] == '1') {
            ans += solve(j + 1, dp, s);
            if (j + 1 < s.size()) {
                ans += solve(j + 2, dp, s);
            }
        } 
        else if (s[j] == '2') {
            ans += solve(j + 1, dp, s);
            if (j + 1 < s.size() && (s[j + 1] >= '0' && s[j + 1] <= '6')) {
                ans += solve(j + 2, dp, s);
            }
        } 
        else if(s[j] == '0') {
            return 0;
        }
        else{
            ans += solve(j + 1, dp, s);
        }
        return dp[j] = ans;
    }

public:
    int numDecodings(string s) {
        unordered_map<int, char> mp;
        vector<int> dp(s.size(), -1);
        for (int i = 0; i < 26; i++) {
            mp[i + 1] = 'a' + i;
        }
        return solve(0, dp, s);
    }
};