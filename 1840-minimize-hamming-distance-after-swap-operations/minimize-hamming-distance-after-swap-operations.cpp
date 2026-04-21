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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = target.size();
        DisjointSet ds(n);
        for(int i = 0; i < allowedSwaps.size(); i++){
            ds.unionByRank(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        unordered_map<int, unordered_set<int>> mp;
        unordered_map<int, int> t; // index -> element
       
        for(int i = 0; i < n; i++){
            t[i] = target[i];
        }
        int hamming = 0;
        // vector<int> contribution(n, -1);
        for(int i = 0; i < n; i++){
            int par = ds.findUPar(i);
            mp[par].insert(i);
        } // indexes who are free to swap if elements at those indexes are same

        for(auto &p : mp){
            unordered_map<int,int> freq;

            // count source values
            for(int idx : p.second){
                freq[source[idx]]++;
            }

            // match with target
            for(int idx : p.second){
                if(freq[target[idx]] > 0){
                    freq[target[idx]]--;  // use it
                } else {
                    hamming++;            // no match possible
                }
            }
        }
        return hamming;
    }
};