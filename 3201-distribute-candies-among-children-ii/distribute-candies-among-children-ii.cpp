class Solution {
public:
    long long nCk(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= n - i + 1;
            res /= i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for (int i = 0; i <= 3; ++i) {
            long long sign = (i % 2 == 0) ? 1 : -1;
            long long term = nCk(3, i) * nCk(n - i * (limit + 1) + 2, 2);
            total += sign * term;
        }
        return total;
    }
};
