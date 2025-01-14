class Solution {
private:
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adjList, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int distU = pq.top().first;
            pq.pop();

            if (distU > dist[u]){
                continue;
            }

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto& time : times) {
            adjList[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        vector<int> result = dijkstra(n, adjList, k - 1);

        int maxDelay = 0;
        for (int i = 0; i < n; i++) {
            if (result[i] == INT_MAX) {
                return -1;  
            }
            maxDelay = max(maxDelay, result[i]);
        }

        return maxDelay;
    }
};
