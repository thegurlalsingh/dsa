class Solution {
    int bs(int i, vector<vector<int>>& p) {
        int target = p[i][1];
        int l = i + 1;
        int r = p.size() - 1;
        int ans = p.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (p[mid][0] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int solve(int i, vector<vector<int>>& p, vector<int>& dp) {
        if (i >= p.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int skip = solve(i + 1, p, dp);
        int nextIndex = bs(i, p);
        int take = p[i][2] + solve(nextIndex, p, dp);
        // if(nextIndex != p.size()){
            // take = p[i][2] + solve(nextIndex, p, dp);
        // }
        return dp[i] = max(take, skip);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> p;
        for (int i = 0; i < startTime.size(); i++) {
            p.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(p.begin(), p.end());
        vector<int> dp(startTime.size(), -1);
        return solve(0, p, dp);
    }
};