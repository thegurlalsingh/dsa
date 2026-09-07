class Solution {
    int solve(int node, vector<vector<pair<int, int>>>& adj, int distanceThreshold){
        int cities = 0;
        vector<int> dist(adj.size(), INT_MAX);
        dist[node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, node});
        while(!q.empty()){
            auto [c, t] = q.top(); q.pop();
            
            for(auto& [neigh, nc] : adj[t]){
                if(dist[neigh] > c + nc){
                    dist[neigh] = c + nc;
                    q.push({dist[neigh], neigh});
                }
            }
        }

        for(int i = 0; i < adj.size(); i++){
            if(dist[i] <= distanceThreshold && i != node){
                cities++;
            }
        }

        return cities;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        int idx = 0;
        int city = INT_MAX;
        for(int i = 0; i < n; i++){
            int t = solve(i, adj, distanceThreshold);
            if(city > t){
                idx = i; city = t;
            }
            if(city == t){
                idx = max(idx, i);
            }
        }

        return idx;
    }
};