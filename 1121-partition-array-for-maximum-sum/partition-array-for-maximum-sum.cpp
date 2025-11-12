class Solution {
public:
    int n, k;
    vector<int> arr;
    vector<int> dp; // memo

    int solve(int i) {
        if (i == n) return 0;           // base: no elements left
        if (dp[i] != -1) return dp[i];  // already computed

        int maxVal = 0, best = 0;
        for (int len = 1; len <= k && i + len <= n; ++len) {
            maxVal = max(maxVal, arr[i + len - 1]);
            best = max(best, maxVal * len + solve(i + len));
        }
        return dp[i] = best;
    }

    int maxSumAfterPartitioning(vector<int>& a, int K) {
        arr = a;
        k = K;
        n = a.size();
        dp.assign(n, -1);
        return solve(0);
    }
};
