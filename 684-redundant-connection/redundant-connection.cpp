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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<vector<int>> up = edges;
        for(int j = 0; j < edges.size(); j++){
                up[j][0] = up[j][0] - 1;
                up[j][1] = up[j][1] - 1;
            }
        
        for(int i = edges.size() - 1; i >= 0; i--){
            
            int comp = 0;
            DisjointSet ds(up.size());
            vector<int> temp = up[i];
            for(int j = 0; j < edges.size(); j++){
                if(i != j){
                    ds.unionByRank(up[j][0], up[j][1]);
                }
            }

            for(int j = 0; j < edges.size(); j++){
                if(ds.findUPar(j) == j){
                    comp++;
                }
            }

            if(comp == 1){
                return edges[i]; 
            }

        }

        return {};
    }
};