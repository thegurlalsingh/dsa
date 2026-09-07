class Solution {
    vector<long long> solve(int n, vector<vector<pair<int, int>>>& adj, int src){
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src}); // for destination to every node distance -> push dest as starting node

        while(!pq.empty()){
            auto [c, p] = pq.top(); pq.pop();
            
            if (c > dist[p]){
                continue;
            }

            for(auto [neigh, nc] : adj[p]){
                if(dist[neigh] > nc + c){
                    dist[neigh] = nc + c;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> rev(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];
            adj[u].push_back({v, c});
            rev[v].push_back({u, c});
        }
        vector<long long> dist1 = solve(n, adj, src1); // this is from src1 -> some index i
        vector<long long> dist2 = solve(n, adj, src2); // this is from src2 -> some index i
        vector<long long> dist3 = solve(n, rev, dest); // this is from dest -> some index i
        long long mini = LLONG_MAX;
        for(int i = 0; i < n; i++){
            if(dist1[i] != LLONG_MAX && dist2[i] != LLONG_MAX && dist3[i] != LLONG_MAX){
                mini = min(mini, dist1[i] + dist2[i] + dist3[i]); // there should be some index where src1 and src2 both can be merged and from that index dest should be reachable
            }
        }
        return mini == LLONG_MAX ? -1 : mini;
    }
};