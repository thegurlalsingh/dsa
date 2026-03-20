class Solution {
    vector<vector<int>> dp;
    vector<vector<bool>> vis;

    int getXOR(vector<int>& nums, int l, int r) {
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            cnt ^= nums[i];
        }
        return cnt;
    }

    int helper(vector<vector<int>>& xr, vector<int>& nums, int idx, int n, int k) {
        if (idx == n && k == 0)
            return 0;
        if (idx == n || k == 0)
            return 1e9;

        if (vis[idx][k])
            return dp[idx][k];
        vis[idx][k] = true;

        int ans = INT_MAX;

        for (int i = idx; i < n; i++) {
            int partCost = xr[idx][i];

            int next = helper(xr, nums, i + 1, n, k - 1);
            if (next == 1e9)
                continue;

            // THIS is the key transition
            ans = min(ans, max(partCost, next));
        }

        return dp[idx][k] = ans;
    }

    bool solve(vector<vector<int>>& xr, vector<int>& nums, int maxXor, int idx,
               int n, int k) {
        int x = helper(xr, nums, idx, n, k);
        return x <= maxXor;
    }

public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();

        dp.assign(n, vector<int>(k + 1, 0));
        vis.assign(n, vector<bool>(k + 1, false));

        vector<vector<int>> xr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                xr[i][j] = getXOR(nums, i, j);
            }
        }

        int low = 0;
        int high = 1e9;
        int ans = INT_MAX;
        // while (low <= high) {
        //     int mid = (low + high) / 2;
        //     if (solve(xr, nums, mid, 0, n, k)) { // trying to minimize xor here and will maximize it in solve function
        //         ans = min(mid, ans);
        //         high = mid - 1;
        //     } else {
        //         low = mid + 1;
        //     }
        // }
        // return ans;

        return helper(xr, nums, 0, n, k);
    }
};