class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findUPar(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv) return false; // cycle detected
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else parent[pv] = pu, rank[pu]++;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        
        vector<int> first, second; // two edges giving same child
        
        // Step 1: detect if any node has two parents
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // v already has a parent → two-parent case
                first = {parent[v], v}; // earlier edge
                second = {u, v};        // later edge
                e[1] = 0;               // invalidate second edge temporarily
            }
        }

        DisjointSet ds(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (v == 0) continue; 
            if (!ds.unite(u, v)) { // cycle detected
                if (first.empty()) {
                    // No two-parent case, return this edge forming cycle
                    return e;
                }
                // There was a two-parent case → return the first one
                return first;
            }
        }

        // If we reach here: no cycle → remove the second edge
        return second;
    }
};
