class Solution {
    vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {
        int V = adj.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int d = top.first;  
            int u = top.second; 
            if (d > dist[u])
                continue;

            for (auto &p : adj[u]) {
                int v = p.first; 
                int w = p.second; 
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;   
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist = dijkstra(adj, k);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};