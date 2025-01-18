class Solution {
private:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  
                queue<int> q;
                q.push(i);
                color[i] = 0;  
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (auto it : graph[node]) {
                        if (color[it] == -1) {  
                            color[it] = !color[node];  
                            q.push(it);
                        } else if (color[it] == color[node]) {  
                            return false;  
                        }
                    }
                }
            }
        }
        
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        
        for (auto& edge : dislikes) {
            int u = edge[0] - 1;  
            int v = edge[1] - 1;  
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        return isBipartite(graph);
    }
};
