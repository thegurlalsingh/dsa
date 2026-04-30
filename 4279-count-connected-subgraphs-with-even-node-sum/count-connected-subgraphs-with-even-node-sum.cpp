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
    bool helper(vector<int>& curr, vector<vector<int>>& edges,
                vector<int>& nums) {
        if (curr.size() == 1 && nums[curr[0]] % 2 == 0) {
            return true;
        }
        unordered_set<int> c;
        for (int i = 0; i < curr.size(); i++) {
            c.insert(curr[i]);
        }

        int sum = 0;
        for (int i = 0; i < curr.size(); i++) {
            sum += nums[curr[i]];
        }

        DisjointSet ds(nums.size());
        for (int i = 0; i < edges.size(); i++) {
            auto p1 = (c.find(edges[i][0]) != c.end());
            auto p2 = (c.find(edges[i][1]) != c.end());
            if (p1 && p2) {
                ds.unionByRank(edges[i][0], edges[i][1]);
            }
        }
        bool connected = true;
        int par = ds.findUPar(curr[0]);
        for (int i = 0; i < curr.size(); i++) {
            if (ds.findUPar(curr[i]) != par) {
                connected = false;
                break;
            }
        }
        return connected && (sum % 2 == 0);
    }

    void solve(int idx, int& ans, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& adj, vector<vector<int>>& edges) {
        if (idx >= nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(i);
            if (helper(curr, edges, nums)) {
                ans++;
            }
            solve(i + 1, ans, nums, curr, adj, edges);
            curr.pop_back();
        }
    }

public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<vector<int>> adj(n);
        vector<int> curr;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(v);
        }
        int ans = 0;
        solve(0, ans, nums, curr, adj, edges);
        return ans;
    }
};