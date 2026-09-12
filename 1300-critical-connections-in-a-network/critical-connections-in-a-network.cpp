class Solution {
    vector<vector<int>> bridges;
    vector<vector<int>> adj;
    vector<int> tin, low; int timer = 0;

    void dfs(int u, int parent){
        tin[u] = low[u] = timer++;
        for(int v : adj[u]){
            if(v == parent){
                continue;
            }
            if(tin[v] != -1){
                low[u] = min(low[u], tin[v]);
            }
            else{
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]){
                    bridges.push_back({u, v});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(auto edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tin.assign(n, -1);
        low.assign(n, -1);
        for(int i = 0; i < n; i++){
            if(tin[i] == -1){
                dfs(i, -1);
            }
        }
        return bridges;
    }
};