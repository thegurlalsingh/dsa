class Solution {
public:
    const long MAX = 1e9;
    const long MIN = 1;

    int help(vector<int>& walls, long low, long high) {
        if (low > high) {
            return 0;
        }
        int left = lower_bound(walls.begin(), walls.end(), low) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), high) - walls.begin();
        return right-left;
    }

    int solve(vector<int>& walls, vector<pair<int, int>>& rob,
              vector<pair<long, long>>& maxDistance, vector<vector<int>>& dp, int i, int dir) {
        
        if (i==maxDistance.size())return 0;
        if (dp[i][dir]!=-1)return dp[i][dir];
        long left = maxDistance[i].first;
        if (dir == 1) {
            left = max(left, maxDistance[i-1].second + 1);
        }
        int opt1 = help(walls,left,rob[i].first)+solve(walls,rob,maxDistance,dp,i+1,0);
        int opt2 = help(walls,rob[i].first,maxDistance[i].second) + solve(walls,rob,maxDistance,dp,i+1,1);
        return dp[i][dir] = max(opt1, opt2);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> rob(n);
        for (int i=0;i<n;i++) {
            rob[i] = {robots[i], distance[i]};
        }
        sort(rob.begin(), rob.end());
        sort(walls.begin(), walls.end());
        vector<pair<long, long>> maxDistance(n);
        for (int i = 0; i < n; i++) {
            long pos = rob[i].first;
            long dis = rob[i].second;
            long temp1 = (i == 0) ? MIN : (long)rob[i - 1].first + 1;
            long temp2 = (i == n - 1) ? MAX : (long)rob[i + 1].first - 1;
            long left = max(pos - dis, temp1);
            long right = min(pos + dis, temp2);
            maxDistance[i] = {left, right};
        }
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(walls, rob, maxDistance, dp, 0, 0);
    }
};