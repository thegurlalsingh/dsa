class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0]; int y1 = points[i][1];
            for(int j = 0; j < points.size(); j++){
                int x2 = points[j][0]; int y2 = points[j][1];
                int dis = abs(x2 - x1) + abs(y2 - y1);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(n, 0); 
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            if (vis[node]) {
                continue;
            }
            vis[node] = 1;
            sum += wt;
            for (auto& it : adj[node]) {
                int neigh = it.first;
                int edgeWt = it.second;

                if (!vis[neigh]) {
                    pq.push({edgeWt, neigh});
                }
            }
        }

        return sum;
    }
};