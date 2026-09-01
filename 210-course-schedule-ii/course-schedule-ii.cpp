class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> s;
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0]; int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            int t = q.front(); q.pop();
            s.push_back(t);
            for(int neigh : adj[t]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        if(s.size() == numCourses){
            return s;
        }
        return {};
    }
};