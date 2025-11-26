typedef long long ll;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<ll> dist1(n + 1, 1e18), dist2(n + 1, 1e18);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        dist1[1] = 0;
        pq.push({0, 1});   // (time, node)

        ll cycle = 2LL * change;

        while (!pq.empty()) {
            auto [t, u] = pq.top(); pq.pop();

            // If we already found second best time for n → return it
            if (u == n && t > dist1[n]) return t;

            for (int v : adj[u]) {
                ll nt = t;

                // check signal color before leaving u
                if ( (nt % cycle) >= change ) {
                    // red → must wait for next cycle start
                    nt = (nt / cycle + 1) * cycle;
                }

                nt += time;  // travel to v

                if (nt < dist1[v]) {
                    dist2[v] = dist1[v];
                    dist1[v] = nt;
                    pq.push({nt, v});
                }
                else if (nt > dist1[v] && nt < dist2[v]) {
                    dist2[v] = nt;
                    pq.push({nt, v});
                }
            }
        }

        return -1; // should never happen
    }
};
