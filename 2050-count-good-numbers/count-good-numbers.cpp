class Solution {
private:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1){
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long even_ways = modPow(5, even_count, MOD);
        long long odd_ways = modPow(4, odd_count, MOD);

        return (even_ways * odd_ways) % MOD;
    }
};
