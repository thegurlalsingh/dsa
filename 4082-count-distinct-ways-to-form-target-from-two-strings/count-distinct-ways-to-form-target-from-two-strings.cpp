const int MOD = 1e9 + 7;

class Solution {
    int solve(int i, int j, int k, string& word1, string& word2, string& target, int dp[][101][101][4], int mask){
        if(k >= target.size()){
            if(mask == 3){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][j][k][mask] != -1){
            return dp[i][j][k][mask];
        }
        long long ans = 0;
        for(int x = i; x < word1.size(); x++){
            if(word1[x] == target[k]){
                if(mask == 2 || mask == 3){
                    ans = (ans + solve(x + 1, j, k + 1, word1, word2, target, dp, 3)) % MOD;
                }
                else{
                    ans = (ans + solve(x + 1, j, k + 1, word1, word2, target, dp, 1))  % MOD;
                }
                
            }
        }

        for(int x = j; x < word2.size(); x++){
            if(word2[x] == target[k]){
                if(mask == 1 || mask == 3){
                    ans = (ans + solve(i, x + 1, k + 1, word1, word2, target, dp, 3)) % MOD;
                }
                else{
                    ans = (ans + solve(i, x + 1, k + 1, word1, word2, target, dp, 2)) % MOD;
                }
                
            }
        }
        return dp[i][j][k][mask] = (int)ans % MOD;
    }
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int dp[101][101][101][4];
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, word1, word2, target, dp, 0);
    }
};