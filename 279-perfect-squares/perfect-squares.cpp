#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool is_perfect_square(long long x) {
        if (x < 0) return false;
        long long r = static_cast<long long>(std::llround(std::sqrt((long double)x)));
        return r * r == x;
    }

    vector<int> dp;

    int solve(int i, int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int numbers = 1e5;
        for (int start = 1; start * start <= n; start++) {
            int sq = start * start;
            numbers = min(numbers, 1 + solve(start, n - sq));
        }
        return dp[n] = numbers;
    }

public:
    int numSquares(int n) {
        dp.assign(n + 1, -1);
        return solve(1, n);
    }
};
