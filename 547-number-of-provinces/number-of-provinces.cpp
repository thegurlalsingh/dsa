class Solution {
    void bfs(vector<vector<int>>& adj, int node, vector<int>& vis){
        int n = vis.size();
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            auto x = q.front(); q.pop();
            if(vis[x]){
                continue;
            }
            vis[x] = 1;
            for (auto neigh : adj[x]) {
                if (!vis[neigh]) {
                    q.push(neigh);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        int count = 0;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                bfs(adj, i, vis);
            }
        }

        return count;
    }
};