class Solution {
    int solve(int i, vector<int>& nums, int target, int calc, vector<vector<int>>& dp){
        if(i >= nums.size()){
            if(calc == target){
                return 0;
            }
            return -1;
        }
        if(dp[i][calc] != -2){
            return dp[i][calc];
        }
        int skip = solve(i + 1, nums, target, calc, dp);
        int take = -1;
        int next = solve(i + 1, nums, target, calc ^ nums[i], dp);
        if(next != -1){
            take = 1 + next;
        }
        return dp[i][calc] = max(take, skip);
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1e5, -2));
        int c = solve(0, nums, target, 0, dp);
        if(c != -1){
            return n - c;
        }
        return -1;
    }
};