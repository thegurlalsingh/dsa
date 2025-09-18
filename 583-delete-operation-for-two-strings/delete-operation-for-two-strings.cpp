class Solution {
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i == s1.size() || j == s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
        } else {
            return dp[i][j] = max(solve(i + 1, j, s1, s2, dp),
                                 solve(i, j + 1, s1, s2, dp));
        }
    }

    bool isSubsequence(string a, string b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }

public:
    int minDistance(string word1, string word2) {
        if (isSubsequence(word1, word2)) {
            return (int)word2.size() - (int)word1.size();
        }
        if (isSubsequence(word2, word1)) {
            return (int)word1.size() - (int)word2.size();
        }

        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int lcs = solve(0, 0, word1, word2, dp);
        return (n - lcs) + (m - lcs);
    }
};
