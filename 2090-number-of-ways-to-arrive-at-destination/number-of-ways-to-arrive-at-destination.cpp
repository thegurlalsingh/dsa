#define MOD 1000000007

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (const auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDist > dist[currentNode]) {
                continue;
            }

            for (auto [nextNode, edgeWeight] : adj[currentNode]) {
                long long newDist = currentDist + edgeWeight;
                
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    ways[nextNode] = ways[currentNode];
                    pq.push({dist[nextNode], nextNode});
                } else if (newDist == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[currentNode]) % MOD;
                }
            }
        }
        
        return ways[n - 1] % MOD;
    }
};
