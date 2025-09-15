class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            int u = it[1]; // prerequisite
            int v = it[0]; // course
            adj[u].push_back(v);  // u → v (u must be done before v));
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo; 

        while(!q.empty()){

            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            // reducing the indegree of adj nodes
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        // if cycle found
        if(topo.size() == numCourses) return topo;
        return {}; // returning empty array if cycle not found
    }
};