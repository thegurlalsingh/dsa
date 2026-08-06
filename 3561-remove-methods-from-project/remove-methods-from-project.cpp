class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // if a method (region) is found suspicious and it has no indegree which is not suspicious, then we can remove that method (region)

        unordered_set<int> non_sus, sus; // using unordered_set instead of vector because when i will find non_sus methods, i will just run find query of unordered_set to check whether current method is present in sus set or not
        vector<vector<int>> adj(n);
        for(int i = 0; i < invocations.size(); i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int t = q.front(); q.pop();
            if(sus.find(t) != sus.end()){
                continue;
            }
            sus.insert(t);
            for(auto neigh : adj[t]){
                q.push(neigh);
            }
        }
        for(int i = 0; i < n; i++){
            if(sus.find(i) == sus.end()){
                non_sus.insert(i);
            }
        }
        vector<int> complete;
        for(int i = 0; i < n; i++){
            complete.push_back(i);
        }
        vector<int> only_non_sus(non_sus.begin(), non_sus.end());
        for(int i = 0; i < invocations.size(); i++){
            int u = invocations[i][0]; int v = invocations[i][1];
            bool find1 = (non_sus.find(u) != non_sus.end());
            bool find2 = (sus.find(v) != sus.end());
            if(find1 && find2){
                return complete;
            }
        }
        return only_non_sus;
    }
};