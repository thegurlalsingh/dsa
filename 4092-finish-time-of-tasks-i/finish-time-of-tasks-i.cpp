class Solution {
    long long solve(int i, vector<vector<int>>& adj, vector<int>& baseTime) {

        // Leaf
        if (adj[i].empty()) {
            return baseTime[i];
        }

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        // Postorder
        for (int child : adj[i]) {
            long long t = solve(child, adj, baseTime);

            mx = max(mx, t);
            mn = min(mn, t);
        }

        long long ownDuration = (mx - mn) + baseTime[i];

        return mx + ownDuration;
    }

public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {

        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        return solve(0, adj, baseTime);
    }
};