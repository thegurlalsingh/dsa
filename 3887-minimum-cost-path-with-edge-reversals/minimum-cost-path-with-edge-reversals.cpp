class Solution {

    int solve(int start, int end, int n,
              vector<vector<pair<int,int>>> &adj,
              vector<int> &dist){

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0,start});

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int d = t.first;
            int node = t.second;

            if(d > dist[node]) continue;

            for(auto [neigh,w] : adj[node]){
                if(d + w < dist[neigh]){
                    dist[neigh] = d + w;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist[end];
    }

public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n), adj_rev(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});

            adj_rev[v].push_back({u,w});
            adj_rev[u].push_back({v,2*w});
        }

        vector<int> dist1(n,INT_MAX), dist2(n,INT_MAX);

        dist1[0] = 0;
        dist2[n-1] = 0;

        solve(0,n-1,n,adj,dist1);
        solve(n-1,0,n,adj_rev,dist2);

        int ans = INT_MAX;

        for(int u=0; u<n; u++){
            for(auto [v,w] : adj[u]){

                if(dist1[u]==INT_MAX || dist2[v]==INT_MAX){
                    continue;
                }

                ans = min(ans, dist1[u] + w + dist2[v]);
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};