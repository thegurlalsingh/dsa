class DisjointSet {
    vector<int> rank, parent;
public:
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
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else parent[ulp_v] = ulp_u, rank[ulp_u]++;
    }
};

class Solution {
    int n;

    bool reachable(int removed, vector<vector<int>>& edges) {
        // create a fresh DSU every call (your missing part)
        DisjointSet ds(n);

        // union all edges except the removed one
        for (int k = 0; k < edges.size(); k++) {
            if (k != removed) {
                ds.unionByRank(edges[k][0], edges[k][1]);
            }
        }

        // check if removing this edge still keeps its endpoints connected
        int u = edges[removed][0];
        int v = edges[removed][1];

        return ds.findUPar(u) == ds.findUPar(v);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();

        // try removing each edge from last to first
        for (int i = n - 1; i >= 0; i--) {
            if (reachable(i, edges)) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
};
