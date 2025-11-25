class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {

        // adjacency list
        vector<vector<pair<int,double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        // max-heap: (probability so far, node)
        priority_queue<pair<double,int>> pq;

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            pq.pop();

            // If this path is already worse, skip
            if (prob < dist[u]) continue;

            // Early stop when reaching end
            if (u == end) return prob;

            for (auto &edge : adj[u]) {
                int v = edge.first;
                double w = edge.second;

                double newProb = prob * w;

                if (newProb > dist[v]) {
                    dist[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0;  // unreachable
    }
};
