class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0}; // this is basically a topological sort problem but for undirected graph which says that whenever you get something like minimum height or finding the roots (becuase they are centre of gravity for trees) just go by this method which is also called peeling of onion method according to which we collect all degrees and push leaves only and then do as like topo sort untill remaining nodes are > 2 rather than old condition of untill queue is empty
        }

        vector<int> degree(n, 0);
        queue<int> q;
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                degree[i]--;
            }
        }

        while (n > 2) {
            int sz = q.size();
            n -= sz;
            while (sz--) {
                auto t = q.front();
                q.pop();
                for (int neigh : adj[t]) {
                    degree[neigh]--;
                    if (degree[neigh] == 1) {
                        q.push(neigh);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};