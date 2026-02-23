const int MOD = 1e9 + 7;

class Solution {

    int dp[151][151];

    int solve(int i, vector<vector<int>>& mat, int g){

        if(i == mat.size()){
            return (g == 1);
        }

        if(dp[i][g] != -1)
            return dp[i][g];

        int ans = 0;

        for(int j = 0; j < mat[0].size(); j++){
            int newG = gcd(g, mat[i][j]);
            ans = (ans + solve(i + 1, mat, newG)) % MOD;
        }

        return dp[i][g] = ans;
    }

public:
    int countCoprime(vector<vector<int>>& mat) {

        memset(dp, -1, sizeof(dp));

        return solve(0, mat, 0);
    }
};