class Solution {
    vector<vector<int>> dp;

    bool match(int i, int j, const string& s, const string& p) {
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if (j == 0) { // pattern empty
            ans = (i == 0);
        } else {
            if (p[j - 1] == '*') {
                char prev = p[j - 2];
                // Zero occurrence
                ans = match(i, j - 2, s, p);
                // One or more occurrence
                if (i > 0 && (s[i - 1] == prev || prev == '.')) {
                    ans = ans || match(i - 1, j, s, p);
                }
            } else {
                if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                    ans = match(i - 1, j - 1, s, p);
                }
            }
        }

        return dp[i][j] = ans;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return match(n, m, s, p);
    }
};
