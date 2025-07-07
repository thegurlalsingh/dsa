class Solution {
    void dfs(int node, vector<bool>& visited, vector<vector<pair<int, int>>>& adj, int mid) {
        visited[node] = true;
        for (auto& [nei, weight] : adj[node]) {
            if (!visited[nei] && weight > mid) {
                dfs(nei, visited, adj, mid);
            }
        }
    }

    bool check(int mid, int k, int n, vector<vector<int>>& edges, vector<vector<pair<int, int>>>& adj) {
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, mid);
                components++;
            }
        }

        return components >= k;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if(edges.empty()){
            return 0;
        }
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> time;
        for(int i = 0; i < edges.size(); i++){
            time.push_back(edges[i][2]);
        }
        sort(time.begin(), time.end());
        int low = 0;
        int high = time.back();

        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, k, n, edges, adj)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
