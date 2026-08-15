typedef tuple<int, int, int, int> T; // cost, index, last char, remaining k

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, -1, k});
        dist[0][k] = 0;

        while (!pq.empty()) {
            auto [cost, index, last_char, k_] = pq.top();
            pq.pop();
            if (cost > dist[index][k_]) {
                continue;
            }
            if (last_char != -1 && last_char == labels[index] && k_ <= 0) {
                continue;
            }
            if (index == n - 1) {
                return cost;
            }
            for (auto& [neigh, neigh_wt] : adj[index]) {
                int neigh_char = labels[neigh];
                int new_wt = neigh_wt + cost;

                if (neigh_char == labels[index]) {
                    if (new_wt < dist[neigh][k_ - 1]) {
                        dist[neigh][k_ - 1] = new_wt;
                        pq.push({new_wt, neigh, neigh_char, k_ - 1});
                    }
                } 
                else {
                    if (new_wt < dist[neigh][k]) {
                        dist[neigh][k] = new_wt;
                        pq.push({new_wt, neigh, neigh_char, k});
                    } // one conceptual mistake i was doing here, i mean it was atmost k consecutive elements allowed so when there is no consecutiveness so it should again become k, it should not be like decreamenting always, it will get reset here 
                }
            }
        }

        return -1;
    }
};