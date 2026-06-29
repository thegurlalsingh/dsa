class Solution {
    double solve(int s, int e, vector<vector<pair<int, double>>>& adj, double ans, vector<int>& vis){
        if(s == e){
            return ans;
        }
        vis[s] = 1;
        for(auto& [neigh, v] : adj[s]){
            if(!vis[neigh]){
                double res = solve(neigh, e, adj, ans * v, vis);
                if(res != -1.0){
                    return res;
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> id;
        int idx = 0;

        for(int i = 0; i < equations.size(); i++){
            if(!id.count(equations[i][0])){
                id[equations[i][0]] = idx++;
            }
            if(!id.count(equations[i][1])){
                id[equations[i][1]] = idx++;
            }
        }

        vector<vector<pair<int, double>>> adj(idx);
        for(int i = 0; i < equations.size(); i++){
            int u = id[equations[i][0]];
            int v = id[equations[i][1]];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0/values[i]});
        }
        vector<double> ans(queries.size(), -1.0);
        for(int i = 0; i < queries.size(); i++){
            if(!id.count(queries[i][0]) || !id.count(queries[i][1])){
                ans[i] = -1.0;
            }
            else{
                vector<int> vis(idx, 0);
                ans[i] = solve(id[queries[i][0]], id[queries[i][1]], adj, 1.0, vis);
            }
        }
        return ans;
    }
};