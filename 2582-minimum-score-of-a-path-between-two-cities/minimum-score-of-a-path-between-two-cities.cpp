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
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        for(int i = 0; i < roads.size(); i++){
            ds.unionByRank(roads[i][0], roads[i][1]);
        }
        sort(roads.begin(), roads.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        for(int i = 0; i < roads.size(); i++){
            if(ds.findUPar(n) == ds.findUPar(roads[i][0])){
                return roads[i][2];
            }
        }
        return -1;
    }
};