class Solution {
    bool solve(int i, vector<int>& nums, vector<vector<int>>& dp, int curr, int sum){
        if(i >= nums.size()){
            if(curr == sum / 2){
                return true;
            }
            return false;
        }
        if(dp[i][curr] != -1){
            return dp[i][curr];
        }

        int take = solve(i + 1, nums, dp, curr + nums[i], sum);
        int skip = solve(i + 1, nums, dp, curr, sum);

        return dp[i][curr] = take || skip;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int halfSum = sum / 2;
        if(sum % 2 != 0 || (sum / 2 != halfSum)){
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum, -1));
        return solve(0, nums, dp, 0, sum);
    }
};