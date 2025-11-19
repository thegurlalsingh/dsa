class Solution {
    vector<vector<int>> dp; // memo: -1 = not computed, 0 = false, 1 = true

    bool match(int i, int j, const string& s, const string& p) {
        if (i < 0 && j < 0) return true;   // both strings finished
        if (j < 0) return false;           // pattern finished, string not
        if (i < 0) {                       // string finished, pattern remains
            // Only valid if remaining pattern is all '*'
            for (int k = 0; k <= j; k++)
                if (p[k] != '*') return false;
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (p[j] == s[i] || p[j] == '?') {
            dp[i][j] = match(i - 1, j - 1, s, p);
        } else if (p[j] == '*') {
            // '*' matches empty sequence OR any character
            dp[i][j] = match(i, j - 1, s, p) || match(i - 1, j, s, p);
        } else {
            dp[i][j] = false;
        }

        return dp[i][j];
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.assign(n, vector<int>(m, -1));
        return match(n - 1, m - 1, s, p);
    }
};
