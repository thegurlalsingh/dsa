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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        
        int n = nums.size();
        DisjointSet ds(n - 1);   // since indices go 0 to n-1
        
        for(int i = 0; i < swaps.size(); i++){
            ds.unionByRank(swaps[i][0], swaps[i][1]);
        }

        // Store indices, NOT values
        unordered_map<int, vector<int>> components;
        for(int i = 0; i < n; i++){
            int root = ds.findUPar(i);
            components[root].push_back(i);
        }

        long long sum = 0;

        for(auto& p : components){
            vector<int>& indices = p.second;

            multiset<int> values;
            for(int idx : indices){
                values.insert(nums[idx]);
            }

            for(int idx : indices){
                if(idx % 2 == 0){
                    auto it = prev(values.end());  // largest
                    sum += *it;
                    values.erase(it);
                }
                else{
                    auto it = values.begin();      // smallest
                    sum -= *it;
                    values.erase(it);
                }
            }
        }

        return sum;
    }
};