class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, adj, vis);
        }
    }

    int components(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        int comp = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                comp++;
            }
        }
        return comp;
    }

    vector<vector<int>> adj(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> a(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];
            if (time > t) {
                a[u].push_back(v);
                a[v].push_back(u);
            }
        }
        return a;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 1e9;
        int ans = 0;
        while (low <= high) {
            int t = (low + high) / 2;
            vector<vector<int>> temp = adj(n, edges, t);
            int comp = components(n, temp);
            if (comp >= k) {
                ans = t;
                high = t - 1;
            } else {
                low = t + 1;
            }
        }
        return ans;
    }
};