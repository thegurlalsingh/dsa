class Solution {
public:
    int n, k;

    long long dp[100005][2][5][5]; // adjust if needed
    bool vis[100005][2][5];

    void solve(int i, vector<int>& nums, int flag, int rem) {
        if (i >= n) return;

        if (vis[i][flag][rem]) return;
        vis[i][flag][rem] = true;

        if (flag == 0) {
            // start new subarray
            int new_rem = nums[i] % k;
            dp[i][flag][rem][new_rem]++;

            solve(i + 1, nums, 1, new_rem);

            for (int r = 0; r < k; r++) {
                dp[i][flag][rem][r] += dp[i + 1][1][new_rem][r];
            }

            // skip
            solve(i + 1, nums, 0, 0);

            for (int r = 0; r < k; r++) {
                dp[i][flag][rem][r] += dp[i + 1][0][0][r];
            }
        } 
        else {
            // extend subarray
            long long new_rem = ((long long)rem * nums[i]) % k;
            dp[i][flag][rem][new_rem]++;

            solve(i + 1, nums, 1, new_rem);

            for (int r = 0; r < k; r++) {
                dp[i][flag][rem][r] += dp[i + 1][1][new_rem][r];
            }

            // stop → do nothing
        }
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;

        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));

        solve(0, nums, 0, 0);

        vector<long long> ans(k, 0);
        for (int r = 0; r < k; r++) {
            ans[r] = dp[0][0][0][r];
        }

        return ans;
    }
};