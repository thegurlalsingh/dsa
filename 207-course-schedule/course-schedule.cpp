class Solution {
    vector<int> topo(int N, vector<vector<int>>& adj) {

        queue<int> q;
        vector<int> indegree(N, 0);

        for (int i = 0; i < N; i++) {
            for (int neigh : adj[i]) {
                indegree[neigh]++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return order;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {

        vector<vector<int>> adj(numCourses);

        for (auto& x : p) {
            adj[x[1]].push_back(x[0]);
        }

        vector<int> t = topo(numCourses, adj);

        return t.size() == numCourses;
    }
};