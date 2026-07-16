class Solution {
    vector<vector<int>> adj;
    vector<int> baseTime;

    long long dfs(int u) {

        if (adj[u].empty()){
            return baseTime[u];
        }

        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;

        for (int v : adj[u]) {

            long long finish = dfs(v);

            mn = min(mn, finish);
            mx = max(mx, finish);
        }

        long long ownDuration = (mx - mn) + baseTime[u];

        return mx + ownDuration;
    }

public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        this->baseTime = baseTime;
        adj.resize(n); 
        for(int i = 0; i < edges.size(); i++){ 
            adj[edges[i][0]].push_back(edges[i][1]); 
        }
        return dfs(0);
    }
};