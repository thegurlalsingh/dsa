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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        DisjointSet ds(accounts.size());
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) != mp.end()) {
                    ds.unionByRank(mp[accounts[i][j]], i);
                }
                mp[accounts[i][j]] = i;
            }
        }

        unordered_map<int, vector<string>> merged;
        for (auto& it : mp) {
            string email = it.first;
            int acc = it.second;
            int parent = ds.findUPar(acc);
            merged[parent].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto& it : merged) {
            int parent = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(accounts[parent][0]);
            for (auto& mail : emails) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};