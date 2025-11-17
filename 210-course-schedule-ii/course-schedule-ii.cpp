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

    void dfs(int node, vector<vector<int>>& adj, vector<int>& state, stack<int>& st){
        state[node] = 1;  // visiting
        
        for (int nxt : adj[node]) {
            if (state[nxt] == 0) {
                dfs(nxt, adj, state, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // create directed graph: a → b
        for (auto &p : prerequisites)
            adj[p[0]].push_back(p[1]);
        
        vector<int> state(numCourses, 0); // 0=unvisited,1=visiting,2=done
        
        // run dfs on each component
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state)) 
                    return {};   // cycle detected
            }
        }
        vector<int> state2(numCourses, 0);
        stack<int> st; vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (state2[i] == 0) {
                dfs(i, adj, state2, st);
            }
        }
        while(!st.empty()){
            res.push_back(st.top()); st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};