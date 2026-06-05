class Solution {
    bool solve(int i, vector<int>& arr, int target, vector<int>& dp, vector<int>& visited){
        if(i >= arr.size() || i < 0){
            return false;
        }

        if(arr[i] == 0){
            return true;
        }

        if(visited[i]) {
            return false;
        }

        visited[i] = 1; // wherever we see something like reachable, can reach, path exists, move left/right, jump forward/backward, teleport, transform -> always think of graph, bfs/dfs etc instead of dp because these can form cycles which dp cant solve

        if(dp[i] != -1){
            return dp[i];
        }

        if(i + arr[i] < arr.size()){
            if(solve(i + arr[i], arr, target, dp, visited)){
                return dp[i] = true;
            }
        }

        if(i - arr[i] >= 0){
            if(solve(i - arr[i], arr, target, dp, visited)){
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int target = -1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                target = i;
                break;
            }
        }
        vector<int> visited(arr.size(), 0);
        vector<int> dp(arr.size(), -1);
        return solve(start, arr, target, dp, visited);
    }
};