class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modexp(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modexp(x, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        vector<long long> mul(n, 1);

        // store small k queries
        vector<vector<vector<int>>> small(B);

        // process queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                // large k → brute
                for (int i = l; i <= r; i += k) {
                    mul[i] = mul[i] * v % MOD;
                }
            } else {
                small[k].push_back({l, r, v});
            }
        }

        // process small k
        for (int k = 1; k < B; k++) {

            for (int rem = 0; rem < k; rem++) {

                vector<long long> pref(n / k + 5, 1);

                // apply queries
                for (auto &q : small[k]) {
                    int l = q[0], r = q[1], v = q[2];

                    if (l % k != rem) continue;

                    int L = (l - rem) / k;
                    int R = (r - rem) / k;

                    pref[L] = pref[L] * v % MOD;
                    pref[R + 1] = pref[R + 1] * modInverse(v) % MOD;
                }

                // prefix multiply
                long long cur = 1;
                for (int i = rem, idx = 0; i < n; i += k, idx++) {
                    cur = cur * pref[idx] % MOD;
                    mul[i] = mul[i] * cur % MOD;
                }
            }
        }

        // apply multipliers
        for (int i = 0; i < n; i++) {
            nums[i] = (long long)nums[i] * mul[i] % MOD;
        }

        // xor result
        int ans = 0;
        for (auto x : nums) ans ^= x;

        return ans;
    }
};