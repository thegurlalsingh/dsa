class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& quiet, vector<int>& result) {
        if (result[node] != -1) {
            return;
        }
        result[node] = node;
        for (int neighbor : adjList[node]) {
            dfs(neighbor, adjList, quiet, result);            
            if (quiet[result[neighbor]] < quiet[result[node]]) {
                result[node] = result[neighbor];
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjList(n); 
        vector<int> result(n, -1); 

        for (const auto& edge : richer) {
            adjList[edge[1]].push_back(edge[0]); 
        }

        for (int i = 0; i < n; i++) {
            dfs(i, adjList, quiet, result);
        }

        return result;
    }
};

