#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> dp;

    int solve(int i, vector<tuple<int,int,int>>& t, int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        // Option 1: Skip current job
        int notTake = solve(i + 1, t, n);

        // Option 2: Take current job
        int next = lower_bound(t.begin(), t.end(), make_tuple(get<1>(t[i]), 0, 0)) - t.begin();
        int take = get<2>(t[i]) + solve(next, t, n);

        return dp[i] = max(take, notTake);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int,int,int>> t;
        for(int i = 0; i < n; i++) {
            t.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(t.begin(), t.end());
        dp.assign(n, -1);
        return solve(0, t, n);
    }
};
