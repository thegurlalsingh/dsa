class DisjointSet {

public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet dsu(n);
        unordered_set<int> s;
        for (int i = 0; i < roads.size(); i++) {
            dsu.unionByRank(roads[i][0] - 1, roads[i][1] - 1);
        }
        vector<int> par = dsu.parent;
        for (int i = 1; i < n; i++) {
            if (dsu.findUPar(i) == dsu.findUPar(0)) {
                s.insert(i);
            }
        }
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0] - 1;
            int v = roads[i][1] - 1;
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        queue<int> q;
        q.push(0);

        int best = INT_MAX;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto& [neigh, wt] : adj[t]) {
                best = min(wt, best);
                if (s.find(neigh) != s.end()) {
                    s.erase(neigh);
                    q.push(neigh);
                }
                
            }
        }
        return best;
    }
};