class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0; // already at all nodes

        int allVisited = (1 << n) - 1;   // bitmask with all bits = 1 (all nodes visited)
        queue<tuple<int,int,int>> q;     // {mask, node, distance}
        vector<vector<bool>> visited(1 << n, vector<bool>(n, false));

        // Multi-source BFS: start from every node
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            q.push({mask, i, 0});
            visited[mask][i] = true;
        }

        // BFS
        while (!q.empty()) {
            auto [mask, node, dist] = q.front();
            q.pop();

            // If all nodes are visited
            if (mask == allVisited)
                return dist;

            // Explore neighbors
            for (int neighbor : graph[node]) {
                int newMask = mask | (1 << neighbor);
                if (!visited[newMask][neighbor]) {
                    visited[newMask][neighbor] = true;
                    q.push({newMask, neighbor, dist + 1});
                }
            }
        }

        return -1; // should never reach here
    }
};
