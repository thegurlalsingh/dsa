class Solution {
    const int MOD = 1e9 + 7;
private:
    vector<int> dijkstra(int n, int source, vector<vector<pair<int, int>>>& graph) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            if (currentDist > dist[currentNode]) continue;

            for (auto& [neighbor, weight] : graph[currentNode]) {
                if (dist[currentNode] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[currentNode] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        return dist;
    }

    int dfsWithCondition(int node, int destination, vector<vector<pair<int, int>>>& graph, vector<int>& dist, vector<int>& memo) {
        if (node == destination) {
            return 1; 
        }
        if (memo[node] != -1) {
            return memo[node]; 
        }

        int count = 0;
        for (auto& [neighbor, weight] : graph[node]) {
            if (dist[node] > dist[neighbor]) { 
                count = (count + dfsWithCondition(neighbor, destination, graph, dist, memo)) % MOD;
            }
        }

        return memo[node] = count; 
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
        vector<int> dist = dijkstra(n, n, adjList);
        vector<int> memo(n + 1, -1);
        return dfsWithCondition(1, n, adjList, dist, memo);
    }
};
