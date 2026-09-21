class Solution {
    int solve(int i, int prev, vector<pair<int, int>>& p, vector<vector<int>>& dp){
        if(i >= p.size()){
            return 0;
        }
        if(dp[i][prev + 1] != -1){
            return dp[i][prev + 1];
        }

        int skip = solve(i + 1, prev, p, dp);
        int take = 0;
        if(prev == -1 || (p[prev].first <= p[i].first)){
            take = p[i].first + solve(i + 1, i, p, dp);
        }
        
        return dp[i][prev + 1] = max(take, skip);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> p;
        for(int i = 0; i < scores.size(); i++){
            p.push_back({scores[i], ages[i]}); // {score, age}
        }
        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            if(a.second == b.second) // if age same prefer sort ascending in score
                return a.first < b.first;
            return a.second < b.second; // else sort ascending in age 
        });
        vector<vector<int>> dp(scores.size() + 1, vector<int>(ages.size() + 1, -1));
        return solve(0, -1, p, dp);
    }
};