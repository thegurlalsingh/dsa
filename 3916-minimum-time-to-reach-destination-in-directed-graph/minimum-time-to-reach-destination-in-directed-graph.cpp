typedef pair<int, int> P; // {node, time}

class cmp {
public:
    bool operator()(P &a, P &b) {
        return a.second > b.second; 
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<pair<int, int>> times(edges.size());

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int s = edges[i][2];
            int e = edges[i][3];

            adj[u].push_back({v, i}); // directed graph ✔️
            times[i] = {s, e};
        }

        priority_queue<P, vector<P>, cmp> pq;
        vector<int> visited(n, 0);

        pq.push({0, 0}); 

        while(!pq.empty()){
            auto [u, time] = pq.top();
            pq.pop();

            if(visited[u]) continue;   
            visited[u] = 1;

            if(u == n - 1) return time;

            for(auto neigh : adj[u]){
                int v = neigh.first;
                int idx = neigh.second;

                int start = times[idx].first;
                int end = times[idx].second;

                if(time <= end){
                    int newTime = max(time, start) + 1;
                    pq.push({v, newTime});
                }
            }
        }

        return -1;
    }
};