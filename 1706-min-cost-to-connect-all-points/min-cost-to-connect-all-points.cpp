class Solution {
    int solve(vector<vector<int>>& points) {
    int n = points.size();
    vector<int> vis(n, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, 0}); 

    int total = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (vis[node]) continue;

        total += wt;

        vis[node] = 1;

        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                int dist = abs(points[node][0] - points[v][0]) +
                           abs(points[node][1] - points[v][1]);

                pq.push({dist, v});
            }
        }

        
    }

    return total;
}
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return solve(points);
    }
};