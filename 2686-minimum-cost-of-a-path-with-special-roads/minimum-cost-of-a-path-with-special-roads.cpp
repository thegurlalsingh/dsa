typedef pair<long long, int> P; // {cost, node}

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {

        // Build the list of “points”
        vector<pair<int,int>> pts;
        pts.push_back({start[0], start[1]}); // 0
        pts.push_back({target[0], target[1]}); // 1

        for (auto &s : specialRoads) {
            pts.push_back({s[0], s[1]});   // start of special
            pts.push_back({s[2], s[3]});   // end of special
        }

        int N = pts.size();

        // adjacency list
        vector<vector<pair<int,long long>>> adj(N);

        // Normal edges: connect every point to every other point (Manhattan)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                long long w = abs(pts[i].first - pts[j].first) +
                              abs(pts[i].second - pts[j].second);
                adj[i].push_back({j, w});
            }
        }

        // Special roads
        int idx = 2;
        for (auto &s : specialRoads) {
            int u = idx;     // (x1, y1)
            int v = idx + 1; // (x2, y2)
            long long cost = s[4];
            adj[u].push_back({v, cost});
            idx += 2;
        }

        // Dijkstra
        vector<long long> dist(N, LLONG_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [c, u] = pq.top();
            pq.pop();
            if (c > dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                long long w = p.second;
                if (c + w < dist[v]) {
                    dist[v] = c + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return (int)dist[1];
    }
};
