class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        queue<int> q;
        
        for(int i = 0; i < graph.size(); i++){
            q.push(i);
            while(!q.empty()){
                int t = q.front(); 
                q.pop();
                if(color[t] == -1){
                    color[t] = 0;
                }
                for(int j : graph[t]){
                    if(color[j] == -1){
                        color[j] = 1 - color[t];
                        q.push(j);
                    }
                    if(color[j] == color[t]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};