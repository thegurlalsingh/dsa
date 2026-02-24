class Solution {
public:
    // Compute square-free form
    int squareFree(int x) {
        int result = 1;

        for (int p = 2; p * p <= x; p++) {
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            if (cnt % 2 == 1) {
                result *= p;
            }
        }

        if (x > 1) result *= x;  // remaining prime

        return result;
    }

    void dfs(int node, int par,
             vector<vector<int>>& adj,
             vector<int>& sf,
             unordered_map<int,int>& freq,
             long long& ans) {

        int val = sf[node];

        // Count matching ancestors
        ans += freq[val];

        freq[val]++;

        for (int neigh : adj[node]) {
            if (neigh == par) continue;
            dfs(neigh, node, adj, sf, freq, ans);
        }

        freq[val]--;  // backtrack
    }

    long long sumOfAncestors(int n,
                             vector<vector<int>>& edges,
                             vector<int>& nums) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Precompute square-free form
        vector<int> sf(n);
        for (int i = 0; i < n; i++) {
            sf[i] = squareFree(nums[i]);
        }

        unordered_map<int,int> freq;
        long long ans = 0;

        dfs(0, -1, adj, sf, freq, ans);

        return ans;
    }
};