class Solution {
private:
    int solve(int sum, vector<int>& nums, int target, vector<int>& dp) {
        if (sum == target) {
            return 1;
        }
        if (sum > target) {
            return 0;
        }
        if (dp[sum] != -1) {
            return dp[sum];
        }

        int totalWays = 0;
        for (int i = 0; i < nums.size(); ++i) {
            totalWays += solve(sum + nums[i], nums, target, dp);
        }

        return dp[sum] = totalWays;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(0, nums, target, dp);
    }
};
