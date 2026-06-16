class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses, 0);
        vector<int> ans;
        queue<int> index;
        for(int i = 0; i < prerequisites.size(); i++){
            inorder[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == 0){
                index.push(i);
            }
        }
        while(!index.empty()){
            int t = index.front(); index.pop();
            ans.push_back(t);
            for(int neigh : adj[t]){
                inorder[neigh]--;
                if(inorder[neigh] == 0){
                    index.push(neigh);
                }
            }
        }
        return ans.size() == numCourses;
    }
};