class Solution {
    int dijkstra(int n, vector<vector<pair<int, int>>> &adj, int s, int d, int k) {
        priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int,int, int>>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));

        dist[s][k + 1] = 0;
        pq.push({0, s, k + 1}); // taking k while doing bfs because k will change doing bfs for different nodes

        while(!pq.empty()) {

            auto [dis, node, k0] = pq.top();
            pq.pop();

            if(node == d && k0 >= 0){
                return dis;
            }
            
            if(k0 < 0){
                continue;
            }

            if(dis > dist[node][k0])
                continue;

            for(auto &it : adj[node]) {

                int neigh = it.first;
                int wt    = it.second;

                if(k0 - 1 >= 0 && (dist[node][k0] + wt < dist[neigh][k0 - 1])) {
                    dist[neigh][k0 - 1] = dist[node][k0] + wt;
                    pq.push({dist[neigh][k0 - 1], neigh, k0 - 1});
                }
            }
        }

        return -1;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        return dijkstra(n, adj, src, dst, k);
    }
};