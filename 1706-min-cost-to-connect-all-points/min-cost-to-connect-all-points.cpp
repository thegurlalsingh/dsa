class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
};

class Solution {
    int manhattan(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        DSU ds(points.size());
        vector<vector<int>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                int p1 = i;
                int p2 = j;
                int dis = manhattan(points[i][0], points[i][1], points[j][0], points[j][1]);
                edges.push_back({p1, p2, dis});
            }
        }
        sort(edges.begin(), edges.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int mstWeight = 0;
        int edgesUsed = 0;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(ds.find(u) == ds.find(v)){
                continue;
            }

            mstWeight += wt;
            edgesUsed++;

            ds.unite(u, v);

            if(edgesUsed == points.size() - 1){
                break;
            }
        }

        return mstWeight;
    }
};