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
        DisjointSet ds(26);
        for(int i = 0; i < equations.size(); i++){
            int chara = equations[i][0] - 'a';
            int charb = equations[i][3] - 'a';
            bool equal = equations[i][1] == '=';

            if(equal){
                ds.unionByRank(chara, charb);
            }

        }

        for(int i = 0; i < equations.size(); i++){
            int chara = equations[i][0] - 'a';
            int charb = equations[i][3] - 'a';
            bool equal = equations[i][1] == '=';

            if(!equal && (ds.findUPar(chara) == ds.findUPar(charb))){
                return false;
            }

        } // dont go in one pass only because see wrong submission, there first inequality is there and then again inequality but it passed return true, so we need a recheck -> thats why first connect all equals and then check if unequal are in same component -> return false else continue
        return true; 
    }
};