class Solution {
    double dijkstra(int s, int e, vector<vector<pair<int, double>>> &adj, int n) {
        priority_queue<pair<double,int>> pq;

        vector<double> dist(n, 0.0);

        dist[s] = 1.0;
        pq.push({1.0, s}); 

        while(!pq.empty()) {

            auto [prob, node] = pq.top();
            pq.pop();

            if(node == e){
                return prob;
            }

            if(prob < dist[node])
                continue;

            for(auto &it : adj[node]) {

                int neigh = it.first;
                double new_prob    = it.second;

                if(dist[node] * new_prob > dist[neigh]) {
                    dist[neigh] = dist[node] * new_prob;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return 0.0;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        return dijkstra(start_node, end_node, adj, n);
    }

};