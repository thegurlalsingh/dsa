class Solution {
public:
    const int MOD = 1000000007;
    int n;
    string s;
    vector<int> last; // last occurrence of each char
    vector<long long> memo;

    long long solve(int idx) {
        if (idx < 0) return 1; // base: empty subsequence
        if (memo[idx] != -1) return memo[idx];

        char c = s[idx];
        long long ans = (2 * solve(idx - 1)) % MOD;

        if (last[c] != -1) {
            ans = (ans - solve(last[c] - 1) + MOD) % MOD;
        }

        last[c] = idx;
        memo[idx] = ans;
        return ans;
    }

    int distinctSubseqII(string _s) {
        s = _s;
        n = s.size();
        last.assign(256, -1);
        memo.assign(n, -1);

        long long ans = solve(n - 1) - 1; // subtract empty subsequence
        return (ans + MOD) % MOD;
    }
};
