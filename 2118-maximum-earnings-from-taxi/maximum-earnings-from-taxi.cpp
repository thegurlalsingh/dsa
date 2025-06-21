class Solution {
private:
    long long solve(int i, vector<vector<int>>& rides, vector<long long>& dp, vector<int>& startTimes) {
        if (i >= rides.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int nextIndex = lower_bound(startTimes.begin(), startTimes.end(), rides[i][1]) - startTimes.begin();

        long long take = (rides[i][1] - rides[i][0] + rides[i][2]) + solve(nextIndex, rides, dp, startTimes);
        long long skip = solve(i + 1, rides, dp, startTimes);

        return dp[i] = max(take, skip);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end()); 

        int sz = rides.size();
        vector<long long> dp(sz, -1);
        vector<int> startTimes;

        for (auto& r : rides) {
            startTimes.push_back(r[0]);
        }

        return solve(0, rides, dp, startTimes);
    }
};
