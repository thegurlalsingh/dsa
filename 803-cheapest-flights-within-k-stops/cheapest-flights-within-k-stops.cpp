typedef pair<int, pair<int, int>> P; 
// {cost, {node, stopsRemaining}}

class Solution {
    int solve(int n, vector<vector<pair<int, int>>> &adj, int src, int dest, int k) {

        priority_queue<P, vector<P>, greater<P>> pq;

        // dist[node][stopsLeft]
        vector<vector<int>> dist(n, vector<int>(k+2, 1e8));

        dist[src][k+1] = 0;                 // we allow k stops → k+1 edges maximum
        pq.push({0, {src, k+1}});

        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int cost = t.first;
            int u = t.second.first;
            int stops = t.second.second;

            if (u == dest) return cost;     // we found the best with valid stops

            if (cost > dist[u][stops]) continue;
            if (stops == 0) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                int newCost = cost + w;
                if (newCost < dist[v][stops - 1]) {
                    dist[v][stops - 1] = newCost;
                    pq.push({newCost, {v, stops - 1}});
                }
            }
        }
        return -1;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        return solve(n, adj, src, dst, k);
    }
};
