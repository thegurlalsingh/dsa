#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1005][3][1005]; // dp[i][sign+1][prev]
    
    int solve(int i, vector<int>& nums, int sign, int prev) {
        if (i == nums.size()) return 0;
        if (dp[i][sign + 1][prev] != -1) return dp[i][sign + 1][prev];

        int take = 0; 
        int skip = solve(i + 1, nums, sign, prev);
        int d = nums[i] - nums[prev];

        if (d != 0 && (sign == 0 || (sign > 0 && d < 0) || (sign < 0 && d > 0))) {
            take = 1 + solve(i + 1, nums, (d > 0 ? 1 : -1), i);
        }

        return dp[i][sign + 1][prev] = max(take, skip);
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return 1 + solve(1, nums, 0, 0);
    }
};
