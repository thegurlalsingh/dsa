class Solution {
public:
    vector<long long> dp;
    int msb;

    long long solve(int mask) {
        if (dp[mask] != -1)
            return dp[mask];

        long long ans = 0;  // default if no number equals this mask

        for (int i = 0; i < msb; i++) {
            if (mask & (1 << i)) {
                ans = max(ans, solve(mask ^ (1 << i)));
            }
        }

        return dp[mask] = ans;
    }

    long long maxProduct(vector<int>& nums) {
        long long res = 0;

        int mx = *max_element(nums.begin(), nums.end());
        msb = log2(mx) + 1;

        dp.assign((1 << msb), -1);

        // base initialization
        for (int mask : nums)
            dp[mask] = mask;

        // compute for all masks lazily
        for (int mask = 0; mask < (1 << msb); mask++)
            solve(mask);

        for (int mask : nums) {
            int complement = mask ^ ((1 << msb) - 1);
            res = max(res, 1LL * mask * dp[complement]);
        }

        return res;
    }
};