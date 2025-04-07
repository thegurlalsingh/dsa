class Solution {
private:
    bool solve(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (idx >= nums.size() || target < 0) {
            return false;
        }
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        bool take = solve(nums, idx + 1, target - nums[idx], dp);
        bool skip = solve(nums, idx + 1, target, dp);

        return dp[idx][target] = take || skip;
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums, 0, target, dp);
    }
};
