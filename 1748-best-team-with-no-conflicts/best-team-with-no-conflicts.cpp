class Solution {
    int solve(int i, int prev, vector<pair<int,int>>& players, vector<vector<int>>& dp) {
        if(i >= players.size()) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        // Option 1: skip current player
        int skip = solve(i + 1, prev, players, dp);

        // Option 2: take current player (if no conflict)
        int take = 0;
        if(prev == -1 || players[prev].second <= players[i].second) {
            take = players[i].second + solve(i + 1, i, players, dp);
        }

        return dp[i][prev + 1] = max(take, skip);
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> players;
        for(int i = 0; i < ages.size(); i++)
            players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end()); // sort by age then score

        int n = players.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // dp[i][prev+1]

        return solve(0, -1, players, dp);
    }
};
