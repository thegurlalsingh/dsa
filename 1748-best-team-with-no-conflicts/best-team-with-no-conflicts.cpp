class Solution {
    int solve(int i, vector<pair<int, int>>& v, int prev, vector<vector<int>>& dp){
        if(i >= v.size()){
            return 0;
        }
        if(dp[i][prev + 1] != -1){
            return dp[i][prev + 1];
        }
        int s = solve(i + 1, v, prev, dp);
        int t = 0;
        if(prev == -1 || (v[i].second >= v[prev].second)){
            t = v[i].second + solve(i + 1, v, i, dp);
        }
        return dp[i][prev + 1] = max(t, s);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> dp(ages.size(), vector<int>(ages.size() + 1, -1));
        vector<pair<int, int>> v;
        for(int i = 0; i < ages.size(); i++){
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        return solve(0, v, -1, dp);
    }
};