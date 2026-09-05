class Solution {
    vector<pair<int, int>> bfs(vector<int>& nums, int sum, int elem){
        vector<pair<int, int>> ans;
        unordered_map<int, int> mp;
        mp[elem] = 0;
        ans.push_back({elem, 0});
        queue<int> q;
        q.push(elem);
        while(!q.empty()){
            int t = q.front(); q.pop();
            if(!mp.count(t * 2) && t * 2 <= 2 * sum){
                mp[t * 2] = mp[t] + 1;
                ans.push_back({t * 2, mp[t] + 1});
                q.push(t * 2);
            }

            if(!mp.count(floor(t / 2)) && floor(t / 2) > 0){
                mp[floor(t / 2)] = mp[t] + 1;
                ans.push_back({floor(t / 2), mp[t] + 1});
                q.push(floor(t / 2));
            }
        }

        return ans;
    }

    int solve(int i, int sum, int currSum, vector<vector<int>>& dp, vector<vector<pair<int, int>>>& ans){
        if(currSum == sum){
            return 0;
        }
        if(currSum < 0 || i >= ans.size()){
            return INT_MAX;
        }
        if(dp[i][currSum] != -1){
            return dp[i][currSum];
        }
        int skip = solve(i + 1, sum, currSum, dp, ans);
        int take = INT_MAX;
        for(int j = 0; j < ans[i].size(); j++){
            if(currSum + ans[i][j].first <= sum){
                int t = solve(i + 1, sum, currSum + ans[i][j].first, dp, ans);
                if(t != INT_MAX){
                    take = min(take, ans[i][j].second + t);
                }
            }
        }
        return dp[i][currSum] = min(skip, take);
    }
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<pair<int, int>>> ans;
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(bfs(nums, sum, nums[i]));
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        int a = solve(0, sum, 0, dp, ans);
        return a == INT_MAX ? -1 : a;
    }
};