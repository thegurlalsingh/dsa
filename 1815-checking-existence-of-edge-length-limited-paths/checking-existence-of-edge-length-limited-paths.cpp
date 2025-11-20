class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[b] < rank[a]) parent[b] = a;
        else parent[b] = a, rank[a]++;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n,
                                           vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries)
    {
        // Add original index to each query
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }

        // sort edges by weight
        sort(edgeList.begin(), edgeList.end(),
             [](auto &a, auto &b){ return a[2] < b[2]; });

        // sort queries by limit
        sort(queries.begin(), queries.end(),
             [](auto &a, auto &b){ return a[2] < b[2]; });

        DSU ds(n);
        vector<bool> ans(queries.size());
        int edgeIndex = 0;

        // process each query in increasing order of limit
        for (auto &q : queries) {
            int u = q[0], v = q[1], limit = q[2], idx = q[3];

            // union all edges with weight < limit
            while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit) {
                ds.unite(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
                edgeIndex++;
            }

            // check connectivity
            ans[idx] = (ds.find(u) == ds.find(v));
        }

        return ans;
    }
};
