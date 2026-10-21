class Solution {
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> actualPrimes;
        for (int i = 0; i <= n; i++) {
            if (isPrime[i]) {
                actualPrimes.push_back(i);
            }
        }

        return actualPrimes;
    }

    int solve(int i, vector<int>& arr, int s, vector<vector<int>>& dp) {
        if (s == 0) {
            return 0;
        }
        if (i >= arr.size() || s < 0) {
            return INT_MAX;
        }
        if (dp[i][s] != -1) {
            return dp[i][s];
        }
        int skip = solve(i + 1, arr, s, dp);
        int take = INT_MAX;
        if (arr[i] <= s) {
            int t = solve(i + 1, arr, s - arr[i], dp);
            if (t != INT_MAX) {
                take = 1 + t;
            }
        }
        return dp[i][s] = min(skip, take);
    }

public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> p = sieve(n);
        if (s == 0 || s == 1) {
            return {};
        }
        vector<vector<int>> dp(p.size(), vector<int>(s + 1, -1));

        int best = s;
        while (best > 0 && solve(0, p, best, dp) == INT_MAX) {
            best--;
        }

        if (best == 0) {
            return {};
        }

        vector<int> ans;
        int sum = best;
        for (int i = 0; i < p.size() && sum > 0; i++) {
            int o = solve(i, p, sum, dp);
            if (p[i] <= sum) {
                int rem = solve(i + 1, p, sum - p[i], dp);
                if (rem != INT_MAX && 1 + rem == o) {
                    ans.push_back(p[i]);
                    sum -= p[i];
                }
            }
        }
        return ans;
    }
};