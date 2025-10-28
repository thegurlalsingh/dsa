class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;

        // dp[day][A used][consecutive L]
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, 0)));

        dp[0][0][0] = 1; // starting state

        for(int day = 0; day < n; day++){
            for(int A = 0; A < 2; A++){
                for(int L = 0; L < 3; L++){
                    long long val = dp[day][A][L];
                    if(!val) continue;

                    // Add 'P'
                    dp[day+1][A][0] = (dp[day+1][A][0] + val) % MOD;

                    // Add 'A'
                    if(A < 1)
                        dp[day+1][A+1][0] = (dp[day+1][A+1][0] + val) % MOD;

                    // Add 'L'
                    if(L < 2)
                        dp[day+1][A][L+1] = (dp[day+1][A][L+1] + val) % MOD;
                }
            }
        }

        long long result = 0;
        for(int A = 0; A < 2; A++)
            for(int L = 0; L < 3; L++)
                result = (result + dp[n][A][L]) % MOD;

        return result;
    }
};
