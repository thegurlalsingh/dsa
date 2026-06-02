
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> up = edges;
        for (int j = 0; j < edges.size(); j++) {
            up[j][0] = up[j][0] - 1;
            up[j][1] = up[j][1] - 1;
        }

        for (int i = edges.size() - 1; i >= 0; i--) {

            int no_of_visited_nodes = 0;

            vector<vector<int>> adj(edges.size());
            vector<int> indegree(edges.size(), 0);

            for (int j = 0; j < edges.size(); j++) {
                if (i != j) {
                    adj[up[j][0]].push_back(up[j][1]);
                    indegree[up[j][1]]++;
                }
            }

            int root = -1;

            for (int i = 0; i < edges.size(); i++) {
                if (indegree[i] == 0) {
                    root = i;
                    break;
                }
            }

            vector<int> visited(edges.size(), -1);

            queue<int> q;
            q.push(root);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                if (visited[node] != -1) {
                    continue;
                }
                visited[node] = 1;
                for (int neigh : adj[node]) {
                    if (visited[neigh] == -1) {
                        q.push(neigh);
                    }
                }
            }

            for (int j = 0; j < visited.size(); j++) {
                if (visited[j] == 1) {
                    no_of_visited_nodes++;
                }
            }

            if (no_of_visited_nodes == edges.size()) {
                return edges[i];
            }
        }

        return {};
    }
};