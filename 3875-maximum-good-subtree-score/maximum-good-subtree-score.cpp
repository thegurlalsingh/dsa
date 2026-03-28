class Solution {
public:
    bool isGood(int val, int mask) {
        int x = val;
        while (val > 0) {
            int rem = val % 10;
            if (mask & 1 << rem)
                return false;
            mask |= (1 << rem);
            val /= 10;
        }
        return true;
    }

    int getMax(int idx, vector<int>& ans, int mask, vector<vector<int>>& dp) {
        if (idx >= ans.size())
            return 0;

        if (dp[idx][mask] != -1)
            return dp[idx][mask];

        int notTake = getMax(idx + 1, ans, mask, dp);
        int take = 0;
        if (isGood(ans[idx], mask)) {
            int x = ans[idx];
            int n_mask = mask;
            while (x > 0) {
                int rem = x % 10;
                n_mask = n_mask | (1 << rem);
                x /= 10;
            }
            take = ans[idx] + getMax(idx + 1, ans, n_mask, dp);
        }

        return dp[idx][mask] = max(take, notTake);
    }

    void dfs(int node, vector<int>& visited,
             unordered_map<int, vector<int>>& adj, vector<int>& val,
             vector<int>& ans) {
        visited[node] = 1;
        ans.push_back(val[node]);

        for (int child : adj[node]) {
            if (!visited[child]) {
                dfs(child, visited, adj, val, ans);
            }
        }

        return;
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = vals.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            if (par[i] != -1) {
                adj[par[i]].push_back(i);
            }
        }

        int ans = 0;
        int mod = 1e9 + 7;

       
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            vector<int> ans2;

            dfs(i, visited, adj, vals, ans2);
            vector<vector<int>> dp(ans2.size() + 1, vector<int>(1025, -1));
            ans = (ans + getMax(0, ans2, 0, dp)) % mod;
        }

        return ans;
    }
};