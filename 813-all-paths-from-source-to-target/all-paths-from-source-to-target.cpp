class Solution {
    void solve(int start, int end, vector<vector<int>>& adj,
               vector<vector<int>>& res, vector<int>& current, vector<int>& visited){

        if(start == end){
            current.push_back(end);
            res.push_back(current);
            current.pop_back();
            return;
        }

        visited[start] = 1;
        current.push_back(start);

        for(int nxt : adj[start]){
            if(!visited[nxt]){
                solve(nxt, end, adj, res, current, visited);
            }
        }

        current.pop_back();
        visited[start] = 0;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        // Build adjacency list
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<vector<int>> res;
        vector<int> current;
        vector<int> visited(n, 0);

        solve(0, n - 1, adj, res, current, visited);
        return res;
    }
};
