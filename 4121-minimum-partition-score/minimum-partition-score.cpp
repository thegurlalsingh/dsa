class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    vector<long long> pref;
    long long INF = 1e18;

    long long dfs(int idx, int k) {
        if (idx == n && k == 0) return 0;
        if (idx == n || k == 0) return INF;

        if (dp[idx][k] != -1) return dp[idx][k];

        long long ans = INF;

        for (int i = idx; i <= n - k; i++) {
            long long curr = pref[i + 1] - pref[idx];
            long long cost = curr * (curr + 1) / 2;

            if (cost >= ans) break;  

            ans = min(ans, cost + dfs(i + 1, k - 1));
        }

        return dp[idx][k] = ans;
    }

    long long minPartitionScore(vector<int>& nums, int k) {
        n = nums.size();

        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        dp.assign(n, vector<long long>(k + 1, -1));

        return dfs(0, k);
    }
};

