class Solution {
    vector<tuple<int, int, int>> bfs(int sum, int elem) {
        vector<tuple<int, int, int>> ans;
        map<pair<int, int>, int> mp;
        queue<pair<int, int>> q;
        mp[{elem, 1}] = 0;
        q.push({elem, 1});
        ans.push_back({elem, 0, 1});
        while (!q.empty()) {
            auto [t, order] = q.front();
            q.pop();
            int cost = mp[{t, order}];
            if (order == 1) {
                long long mul = 2LL * t;
                if (mul <= 2LL * sum &&
                    !mp.count({(int)mul, 1})) {
                    mp[{(int)mul, 1}] = cost + 1;
                    q.push({(int)mul, 1});
                    ans.push_back({(int)mul, cost + 1, 1});
                }
            }

            int div = t / 2;
            if (div > 0 && !mp.count({div, 2})) {
                mp[{div, 2}] = cost + 1;
                q.push({div, 2});
                ans.push_back({div, cost + 1, 2});
            }
        }

        return ans;
    }


    int solve(int i, int sum, int currSum, vector<vector<int>>& dp, vector<vector<tuple<int, int, int>>>& ans) {
        if (currSum == sum) {
            return 0;
        }
        if (i >= ans.size()) {
            return INT_MAX;
        }
        if (dp[i][currSum] != -1) {
            return dp[i][currSum];
        }
        int skip = solve(i + 1, sum, currSum, dp, ans);
        int take = INT_MAX;
        for (auto [value, oper, order] : ans[i]) {
            if (currSum + value > sum) {
                continue;
            }
            int t = solve(i + 1, sum, currSum + value, dp, ans);
            if (t != INT_MAX) {
                take = min(take, oper + t);
            }
        }
        return dp[i][currSum] = min(skip, take);
    }


public:

    int minOperations(vector<int>& nums, int sum) {
        vector<vector<tuple<int, int, int>>> ans;
        for (int x : nums) {
            ans.push_back(bfs(sum, x));
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        int ansValue = solve(0, sum, 0, dp, ans);

        return ansValue == INT_MAX ? -1 : ansValue;
    }
};