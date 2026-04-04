class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<vector<int>> rev_adj(n);
        for (int j = 0; j < adj.size(); j++) {
            for (int i = 0; i < adj[j].size(); i++) {
                rev_adj[adj[j][i]].push_back(j);
            }
        }
        vector<int> bitmask_parent(n);
        for (int i = 0; i < rev_adj.size(); i++) {
            vector<int> temp = rev_adj[i];
            int mask = 0;
            if (!temp.empty()) {
                mask = (1 << temp[0]);
                for (int j = 1; j < temp.size(); j++) {
                    mask = mask | (1 << temp[j]);
                }
            }
            bitmask_parent[i] = mask; // bitmask of all nodes which are visiting this node
        }

        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1)
                continue;

            int pos = __builtin_popcount(mask) + 1;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v))
                    continue;

                int parent_mask = bitmask_parent[v];

                if ((mask & parent_mask) == parent_mask) {
                    int new_mask = mask | (1 << v);

                    dp[new_mask] = max(dp[new_mask], dp[mask] + score[v] * pos);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};