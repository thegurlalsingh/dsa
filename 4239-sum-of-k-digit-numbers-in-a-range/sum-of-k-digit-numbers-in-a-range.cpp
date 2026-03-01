class Solution {
    const long long MOD = 1e9 + 7;

    // Fast exponentiation
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    // Modular inverse using Fermat (MOD must be prime)
    long long modInverse(long long x) { return power(x, MOD - 2); }

public:
    int sumOfNumbers(int l, int r, int k) {
        

        long long D = (r - l + 1) % MOD;

        // S = sum of digits from l to r
        long long S = ((r - l + 1) * (l + r) / 2) % MOD;

        long long D_pow = power(D, k - 1);
        long long ten_pow = power(10, k);

        long long geom = (ten_pow - 1 + MOD) % MOD;
        geom = (geom * modInverse(9)) % MOD;

        long long ans = S;
        ans = (ans * D_pow) % MOD;
        ans = (ans * geom) % MOD;

        return ans;
    }
};