class Solution {
    int solve(int i, vector<tuple<int, int, int>>& v, vector<int>& dp, int prev){
        if(i >= v.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int skip = solve(i + 1, v, dp, prev);
        
        int x = get<1>(v[i]);
        int idx = lower_bound(v.begin(), v.end(), make_tuple(x, 0, 0)) - v.begin();

        int take = get<2>(v[i]) + solve(idx, v, dp, i);
    
        return dp[i] = max(take, skip);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> v;
        for(int i = 0; i < startTime.size(); i++){
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end());
        vector<int> dp(startTime.size(), -1);
        return solve(0, v, dp, -1);
    }
};