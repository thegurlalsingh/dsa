class Solution {

    void solve(int i, vector<vector<int>>& stations, vector<long long>& dp) {

        if (i == stations.size()) {
            return;
        }

        long long position = stations[i][0];
        long long fuel = stations[i][1];

        for (int stops = i; stops >= 0; stops--) {

            if (dp[stops] >= position) {

                dp[stops + 1] = max(dp[stops + 1], dp[stops] + fuel);
            }
        }

        solve(i + 1, stations, dp);
    }

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        int n = stations.size();

        vector<long long> dp(n + 1, 0);

        dp[0] = startFuel;

        solve(0, stations, dp);

        for (int stops = 0; stops <= n; stops++) {

            if (dp[stops] >= target) {
                return stops;
            }
        }

        return -1;
    }
};