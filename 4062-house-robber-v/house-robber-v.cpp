class Solution {
    long long solve(int i, bool prevTaken, vector<int>& nums, vector<int>& colors, vector<vector<long long>>& dp) {

        if(i >= nums.size()) {
            return 0;
        }

        if(dp[i][prevTaken] != -1) {
            return dp[i][prevTaken];
        }

        long long way1 = solve(i + 1, false, nums, colors, dp);

        long long way2 = 0;
        if(i == 0 || !prevTaken || colors[i] != colors[i - 1]) {
            way2 = nums[i] + solve(i + 1, true, nums, colors, dp);
        }

        return dp[i][prevTaken] = max(way1, way2);
    }

public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, false, nums, colors, dp);
    }
};
