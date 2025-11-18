class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1, 0);
        
        for(auto &r : relations){
            adj[r[0]].push_back(r[1]);
            indeg[r[1]]++;
        }

        queue<int> q;
        vector<int> dist(n+1, 0);

        for(int i = 1; i <= n; i++){
            if(indeg[i] == 0){
                dist[i] = time[i-1];   // finish time = own time
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front(); 
            q.pop();

            for(int v : adj[u]){
                // we want maximum finish time among prerequisites
                dist[v] = max(dist[v], dist[u] + time[v-1]);
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        return *max_element(dist.begin(), dist.end());
    }
};
