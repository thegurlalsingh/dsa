class Solution {
    vector<int> tin, low;
    vector<int> vis;
    vector<vector<int>> bridges;

    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& adj) {

        vis[node] = 1;

        tin[node] = low[node] = timer++;

        for (int neigh : adj[node]) {

            if (neigh == parent)
                continue;

            if (!vis[neigh]) {

                dfs(neigh, node, adj);

                low[node] = min(low[node], low[neigh]);

                if (low[neigh] > tin[node]) {

                    bridges.push_back({node, neigh});
                }
            } else {

                low[node] = min(low[node], tin[neigh]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        tin.resize(n);
        low.resize(n);
        vis.resize(n);

        dfs(0, -1, adj);
        return bridges;
    }
};