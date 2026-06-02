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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisjointSet ds(n);
        for(auto &p : pairs) {
            ds.unionByRank(p[0], p[1]);
        }
        unordered_map<int, vector<int>> comp;
        for(int i = 0; i < n; i++) {
            comp[ds.findUPar(i)].push_back(i);
        }
        string ans = s;
        for(auto &it : comp) {
            vector<int>& idx = it.second;
            string chars = "";
            for(int i : idx) {
                chars += s[i];
            }
            sort(idx.begin(), idx.end());
            sort(chars.begin(), chars.end());
            for(int k = 0; k < idx.size(); k++) {
                ans[idx[k]] = chars[k];
            }
        }

        return ans;
    }
};