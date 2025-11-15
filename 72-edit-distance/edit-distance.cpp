class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string& word1, string& word2){
        if (i == word1.size())
            return word2.size() - j;

        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int insert = INT_MAX, del = INT_MAX, replace = INT_MAX, skip = INT_MAX;

        if (word1[i] != word2[j]) {
            replace = 1 + solve(i + 1, j + 1, word1, word2);
            del     = 1 + solve(i + 1, j,     word1, word2);
            insert  = 1 + solve(i,     j + 1, word1, word2);
        } 
        else {
            skip = solve(i + 1, j + 1, word1, word2);
        }

        return dp[i][j] = min({replace, del, insert, skip});
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return solve(0, 0, word1, word2);
    }
};
