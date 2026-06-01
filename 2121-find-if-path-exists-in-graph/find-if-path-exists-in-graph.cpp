class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0]; int v = edges[i][1];
            adj[u].push_back(v); adj[v].push_back(u);
        }

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(source);
        while(!q.empty()){
            int t = q.front(); q.pop();
            if(t == destination){
                return true;
            }
            if(visited[t]){
                continue;
            }
            visited[t] = 1;
            for(int neigh : adj[t]){
                q.push(neigh);
            }
        }

        return false;
    }
};