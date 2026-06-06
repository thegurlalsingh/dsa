class Solution {
    int solve(int s, int e, vector<int>& dp, vector<int>& nums){
        if(s == e){
            return nums[s];
        }

        if(s > e){
            return 0;
        }

        if(dp[s] != -1){
            return dp[s];
        }

        int skip = solve(s + 1, e, dp, nums);
        int take = solve(s + 2, e, dp, nums) + nums[s];;

        return dp[s] = max(skip, take);

    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(solve(0, nums.size() - 2, dp1, nums), solve(1, nums.size() - 1, dp2, nums));
    }
};