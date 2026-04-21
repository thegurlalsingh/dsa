class Solution {
public:
    int maxSum(vector<int>& nums, int K, int m) {
        int n = nums.size();

        vector<long long> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        // dp[i] = dp[i][previous k]
        vector<long long> dp(n + 1, 0);

        // we build answer for k = 1 → K
        for (int k = 1; k <= K; k++) {

            vector<long long> newdp(n + 1, INT_MIN);

            // Step 1: build val[]
            vector<long long> val(n, INT_MIN);
            for (int end = 0; end < n; end++) {
                if (dp[end + 1] != INT_MIN) {
                    val[end] = pref[end] + dp[end + 1];
                }
            }

            // Step 2: build best[]
            vector<long long> best(n);
            best[n - 1] = val[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                best[i] = max(val[i], best[i + 1]);
            }

            for (int i = n - 1; i >= 0; i--) {

                // skip
                newdp[i] = newdp[i + 1];

                // take
                int idx = i + m - 1;
                if (idx < n && best[idx] != INT_MIN) {
                    long long take = best[idx] - (i == 0 ? 0 : pref[i - 1]);
                    newdp[i] = max(newdp[i], take);
                }
            }

            dp = newdp; // move to next k
        }

        return dp[0];
    }
};