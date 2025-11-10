class Solution {
    int dp[505][505]; // dp[i][time] = max satisfaction starting from i with given time
    
    int solve(int i, int time, vector<int>& satisfaction){
        if(i >= satisfaction.size()) return 0;

        if(dp[i][time] != -1) return dp[i][time];

        int skip = solve(i + 1, time, satisfaction);
        int take = (time * satisfaction[i]) + solve(i + 1, time + 1, satisfaction);

        return dp[i][time] = max(take, skip);
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, satisfaction);
    }
};
