class Solution {
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i >= word1.size() && j >= word2.size()){
            return 0;
        }
        if(i >= word1.size()){
            return word2.size() - j;
        }
        if(j >= word2.size()){
            return word1.size() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int way1 = INT_MAX, way2 = INT_MAX, way3 = INT_MAX, skip = INT_MAX; 
        if(word1[i] == word2[j]){
            skip = solve(i + 1, j + 1, word1, word2, dp);
        }
        way1 = 1 + solve(i, j + 1, word1, word2, dp);
        way2 = 1 + solve(i + 1, j, word1, word2, dp);
        way3 = 1 + solve(i + 1, j + 1, word1, word2, dp);

        return dp[i][j] = min({way1, way2, way3, skip});
    }
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size()){ // word1 will always be bigger
            swap(word1, word2);
        }
        vector<vector<int>> dp(word1.size(), vector<int>(word1.size(), -1));
        return solve(0, 0, word1, word2, dp);
    }
};