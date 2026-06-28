class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int farthest = 0;
        int n = s.size();
        vector<int> visited(s.size(), 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int t = q.front(); q.pop();
            int start = max(t + minJump, farthest + 1);
            int end = min(t + maxJump, n - 1);
            for(int i = start; i <= end; i++){
                if(s[i] == '0' && !visited[i]){
                    if(i == s.size() - 1){
                        return true;
                    }
                    visited[i] = true;
                    q.push(i);
                }
            }
            farthest = max(end, farthest);
        }
        return false;
    }
};