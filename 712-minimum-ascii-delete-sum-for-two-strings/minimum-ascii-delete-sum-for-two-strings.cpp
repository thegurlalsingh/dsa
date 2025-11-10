class Solution {
    string s1, s2;
    vector<vector<int>> dp;

    int solve(int i, int j) {
        // base cases
        if (i == s1.size() && j == s2.size()) return 0;

        if (i == s1.size()) { // s1 exhausted, delete remaining s2 chars
            int sum = 0;
            for (int k = j; k < s2.size(); k++) sum += s2[k];
            return sum;
        }

        if (j == s2.size()) { // s2 exhausted, delete remaining s1 chars
            int sum = 0;
            for (int k = i; k < s1.size(); k++) sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(i + 1, j + 1);
        }

        int del1 = s1[i] + solve(i + 1, j);
        int del2 = s2[j] + solve(i, j + 1);

        return dp[i][j] = min(del1, del2);
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        dp.assign(s1.size(), vector<int>(s2.size(), -1));
        return solve(0, 0);
    }
};
