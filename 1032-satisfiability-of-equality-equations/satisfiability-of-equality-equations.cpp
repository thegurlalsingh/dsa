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
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        DisjointSet ds(26);
        for(int i = 0; i < n; i++){
            if(equations[i][1] == '='){
                ds.unionByRank(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }
        for(int i = 0; i < n; i++){
            if(equations[i][1] == '!'){
                if(ds.findUPar(equations[i][0] - 'a') == ds.findUPar(equations[i][3] - 'a')){
                    return false;
                }
            }
        }
        return true;
    }
};