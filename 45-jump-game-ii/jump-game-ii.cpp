class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size())
            return INT_MAX;

        if(i == nums.size() - 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;
        for(int j = 1; j <= nums[i]; j++) {
            int t = solve(i + j, nums, dp);
            if(t != INT_MAX)
                ans = min(ans, 1 + t);
        }

        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};