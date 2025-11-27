class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>>& adj, vector<int>& dist, int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});   // {distance, node}

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int w = nbr.second;

                if (d + w < dist[adjNode]) {
                    dist[adjNode] = d + w;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

        vector<vector<pair<int,int>>> adj(n);
        if (edges.empty()) return 1;

        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c + 1});
            adj[v].push_back({u, c + 1});
        }

        vector<int> dist(n, 1e9);
        dijkstra(adj, dist, n);

        int ans = 0;

        for (int i = 0; i < n; i++)
            if (dist[i] <= maxMoves)
                ans++;

        for (auto &e : edges) {
            int a = e[0], b = e[1], c = e[2];

            int reachA = max(0, maxMoves - dist[a]);
            int reachB = max(0, maxMoves - dist[b]);

            ans += min(c, reachA + reachB);
        }

        return ans;
    }
};
