class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;

    ll solve(int ch, int len, int n, vector<vector<ll>>& dp) {
        if (len == n) return 1;                // base: formed string of length n
        if (dp[ch][len] != -1) return dp[ch][len];  // memoized result

        ll ans = 0;
        if (ch == 0) ans = solve(1, len + 1, n, dp);                       // 'a' → 'e'
        else if (ch == 1) ans = (solve(0, len + 1, n, dp) + solve(2, len + 1, n, dp)) % MOD; // 'e' → 'a'/'i'
        else if (ch == 2) ans = (solve(0, len + 1, n, dp) + solve(1, len + 1, n, dp)
                               + solve(3, len + 1, n, dp) + solve(4, len + 1, n, dp)) % MOD; // 'i' → 'a','e','o','u'
        else if (ch == 3) ans = (solve(2, len + 1, n, dp) + solve(4, len + 1, n, dp)) % MOD; // 'o' → 'i','u'
        else ans = solve(0, len + 1, n, dp);                                              // 'u' → 'a'

        return dp[ch][len] = ans % MOD;
    }

    int countVowelPermutation(int n) {
        vector<vector<ll>> dp(5, vector<ll>(n + 1, -1));
        ll ans = 0;
        for (int ch = 0; ch < 5; ch++) {
            ans = (ans + solve(ch, 1, n, dp)) % MOD;
        }
        return ans;
    }
};
