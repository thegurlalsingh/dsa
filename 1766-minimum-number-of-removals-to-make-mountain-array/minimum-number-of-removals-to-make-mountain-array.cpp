class Solution {
    vector<int> lis_dp, lds_dp;

    int LIS(int i, vector<int>& arr) {
        if (lis_dp[i] != -1) return lis_dp[i];
        int best = 1;
        for (int prev = 0; prev < i; prev++) {
            if (arr[prev] < arr[i]) {
                best = max(best, 1 + LIS(prev, arr));
            }
        }
        return lis_dp[i] = best;
    }

    int LDS(int i, vector<int>& arr) {
        if (lds_dp[i] != -1) return lds_dp[i];
        int best = 1;
        for (int next = i + 1; next < arr.size(); next++) {
            if (arr[next] < arr[i]) {
                best = max(best, 1 + LDS(next, arr));
            }
        }
        return lds_dp[i] = best;
    }

public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        lis_dp.assign(n, -1);
        lds_dp.assign(n, -1);

        // Precompute LIS and LDS for all indices
        for (int i = 0; i < n; i++) LIS(i, arr);
        for (int i = 0; i < n; i++) LDS(i, arr);

        int max_mountain = 0;
        for (int i = 1; i < n - 1; i++) {  // peak cannot be first or last
            if (lis_dp[i] > 1 && lds_dp[i] > 1) { // valid mountain
                max_mountain = max(max_mountain, lis_dp[i] + lds_dp[i] - 1);
            }
        }

        return n - max_mountain;
    }
};
