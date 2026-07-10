class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }

        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            auto t = q.front(); q.pop();
            ans.push_back(t);
            for(int neigh : adj[t]){
                inorder[neigh]--;
                if(inorder[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        if(numCourses == ans.size()){
            return true;
        }
        return false;
    }
};