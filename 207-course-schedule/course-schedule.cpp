class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        state[node] = 1;  // visiting
        
        for (int nxt : adj[node]) {
            if (state[nxt] == 0) {
                if (!dfs(nxt, adj, state)) return false;
            }
            else if (state[nxt] == 1) {
                return false;   // cycle found
            }
        }
        
        state[node] = 2;  // finished
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        // create directed graph: a → b
        for (auto &p : prerequisites)
            adj[p[0]].push_back(p[1]);
        
        vector<int> state(numCourses, 0); // 0=unvisited,1=visiting,2=done
        
        // run dfs on each component
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state)) 
                    return false;   // cycle detected
            }
        }
        
        return true;  // no cycle
    }
};
