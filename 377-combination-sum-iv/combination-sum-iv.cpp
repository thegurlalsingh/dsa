class Solution {
    int solve(int rem, vector<int>& nums, vector<int>& dp) {
        if (rem == 0)
            return 1;

        if (rem < 0)
            return 0;

        if (dp[rem] != -1)
            return dp[rem];

        long long ans = 0;

        for (int x : nums) {
            ans += solve(rem - x, nums, dp);
        }

        return dp[rem] = ans;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(target, nums, dp);
    }
};