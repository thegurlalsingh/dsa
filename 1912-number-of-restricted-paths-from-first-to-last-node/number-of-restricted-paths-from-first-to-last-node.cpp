class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }
        vector<int> dist(n+1, INT_MAX);
        vector<int> dp(n+1, 0);

        dist[n] = 0;
        dp[n] = 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, n);

        const int k_Mod = 1e9 + 7;

        while (!pq.empty()) {
            pair<int, int> u_p = pq.top();
            pq.pop();
            int u_vertex = u_p.second;
            int u_cost = u_p.first;
            if(u_cost > dist[u_vertex]){
                continue;
            }
            if(u_vertex == 1){
                break;
            }
            for(pair<int, int>& v_p : graph[u_vertex]){
                int v_vertex = v_p.first;
                int v_cost = u_cost+v_p.second;
                if(dist[v_vertex] != dist[u_vertex]){
                    dp[v_vertex]+=dp[u_vertex];
                    dp[v_vertex]%=k_Mod;
                }
                if(v_cost > dist[v_vertex]){
                    continue;
                }
                if(v_cost < dist[v_vertex]){
                    dist[v_vertex] = v_cost;
                    pq.emplace(v_cost, v_vertex);
                }
            }
        }
        return dp[1];
    }
};