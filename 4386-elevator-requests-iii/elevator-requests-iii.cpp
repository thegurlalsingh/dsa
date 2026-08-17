class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();
        int fullMask = (1 << m) - 1;

        const long long INF = 1e18;

        // dp[mask][i] = minimum time at which
        // all requests in mask are fulfilled
        // and elevator is at request i's floor.
        vector<vector<long long>> dp(
            1 << m,
            vector<long long>(m, INF)
        );

        // Choose the first request.
        for (int i = 0; i < m; i++) {
            long long travel = abs(start - requests[i][1]);

            long long time = max(
                travel,
                (long long)requests[i][0]
            );

            dp[1 << i][i] = time;
        }

        // Try every subset of fulfilled requests.
        for (int mask = 0; mask <= fullMask; mask++) {

            // Try every possible current request.
            for (int current = 0; current < m; current++) {

                if (dp[mask][current] == INF) {
                    continue;
                }

                long long currentTime = dp[mask][current];

                // Try fulfilling request i next.
                for (int i = 0; i < m; i++) {

                    // Already fulfilled.
                    if (mask & (1 << i)) {
                        continue;
                    }

                    long long travel =
                        abs(requests[current][1] - requests[i][1]);

                    long long arrivalAtFloor =
                        currentTime + travel;

                    long long newTime =
                        max(
                            arrivalAtFloor,
                            (long long)requests[i][0]
                        );

                    int newMask = mask | (1 << i);

                    dp[newMask][i] =
                        min(dp[newMask][i], newTime);
                }
            }
        }

        long long ans = INF;

        for (int i = 0; i < m; i++) {
            ans = min(ans, dp[fullMask][i]);
        }

        return ans;
    }
};