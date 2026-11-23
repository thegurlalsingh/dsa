typedef tuple<long long, int, int> T; // {time, from, node}

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<int> hits(n, 0);
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<long long> dist(n, -1);

        vector<vector<pair<int, int>>> adj(n);
        vector<unordered_set<int>> seen(n);
        vector<bool> active(n, false);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];

            adj[u].push_back({v, d});
        }

        dist[0] = 0;
        active[0] = true;

        for(auto [v, d] : adj[0]){
            pq.push({d, 0, v});
        }

        // for(int i = 1; i < n; i++){
        //     if(requiredSignals[i] == 0){
        //         dist[i] = 0;
        //         active[i] = true;

        //         for(auto [v, d] : adj[i]){
        //             pq.push({d, i, v});
        //         }
        //     }
        // }

        while(!pq.empty()){
            auto [time, from, node] = pq.top();
            pq.pop();

            if(active[node]) {
                continue;
            }

            if(seen[node].count(from)) {
                continue;
            }

            seen[node].insert(from);
            hits[node]++;

            if(hits[node] == requiredSignals[node]){
                dist[node] = time;
                active[node] = true;

                for(auto [v, d] : adj[node]){
                    pq.push({time + d, node, v});
                }
            }
        }

        return dist;
    }
};