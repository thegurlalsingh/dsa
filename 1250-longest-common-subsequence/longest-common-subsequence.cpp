class Solution {
    string text1, text2;
    vector<vector<int>> dp;

    int solve(int i, int j) {
        if (i == text1.size() || j == text2.size()) return 0; 
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1);
        } else {
            return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        dp.assign(text1.size(), vector<int>(text2.size(), -1));
        return solve(0, 0);
    }
};