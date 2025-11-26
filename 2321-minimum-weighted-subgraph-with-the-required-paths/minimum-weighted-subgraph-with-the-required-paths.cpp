typedef long long ll;
typedef pair<ll, int> P;   // (cost, node)

class Solution {
    vector<ll> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<ll> dist(n, 1e18);
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (cost > dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                ll w = p.second;

                if (cost + w < dist[v]) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges,
                            int src1, int src2, int dest) {

        // normal graph
        vector<vector<pair<int,int>>> adj(n);

        // reversed graph
        vector<vector<pair<int,int>>> rev(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            rev[v].push_back({u, w});   // reverse edge
        }

        // run Dijkstra 3 times
        vector<ll> d1 = dijkstra(n, adj, src1);  // src1 -> every node
        vector<ll> d2 = dijkstra(n, adj, src2);  // src2 -> every node
        vector<ll> dt = dijkstra(n, rev, dest);  // every node -> dest

        ll ans = 1e18;

        // try every meeting point X
        for (int X = 0; X < n; X++) {
            if (d1[X] == 1e18 || d2[X] == 1e18 || dt[X] == 1e18) continue;

            ans = min(ans, d1[X] + d2[X] + dt[X]);
        }

        return ans == 1e18 ? -1 : ans;
    }
};
