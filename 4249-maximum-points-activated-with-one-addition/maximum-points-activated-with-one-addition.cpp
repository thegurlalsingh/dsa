class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {

        unordered_map<int,int> compX, compY;
        int idX = 0, idY = 0;

        // compress x
        for(auto &p : points){
            if(!compX.count(p[0]))
                compX[p[0]] = idX++;
        }

        // compress y
        for(auto &p : points){
            if(!compY.count(p[1]))
                compY[p[1]] = idY++;
        }

        int offset = idX;

        DisjointSet ds(idX + idY + 5);

        for(auto &p : points){
            int x = compX[p[0]];
            int y = compY[p[1]] + offset;
            ds.unionByRank(x , y);
        }

        unordered_map<int,int> compSize;

        for(auto &p : points){
            int x = compX[p[0]];
            int parent = ds.findUPar(x);
            compSize[parent]++;
        }

        vector<int> v;
        for(auto &it : compSize)
            v.push_back(it.second);

        sort(v.rbegin(), v.rend());

        if(v.size() == 1) return v[0] + 1;

        return v[0] + v[1] + 1;
    }
};