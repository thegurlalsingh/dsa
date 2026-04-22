class Solution {
public:
    int minCost(int prev,int i,vector<int>& nums,int remSize,vector<vector<int>>& dp){
        if(remSize==1) return dp[prev][i] = nums[prev];
        else if(remSize==2) return dp[prev][i] = max(nums[i],nums[prev]);
        else{
            if(dp[prev][i]!=-1) return dp[prev][i];
            int pick12 = INT_MAX;
            int pick23 = INT_MAX;
            int pick13 = INT_MAX;

            pick12 = max(nums[prev],nums[i]) + minCost(i+1,i+2,nums,remSize-2,dp);
            pick23 = max(nums[i],nums[i+1]) + minCost(prev,i+2,nums,remSize-2,dp);
            pick13 = max(nums[prev],nums[i+1]) + minCost(i,i+2,nums,remSize-2,dp);

            return dp[prev][i] = min(pick12,min(pick23,pick13));
        }
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int n12 = max(nums[0],nums[1]) + minCost(2,3,nums,n-2,dp);
        int n23 = max(nums[1],nums[2]) + minCost(0,3,nums,n-2,dp);
        int n13 = max(nums[0],nums[2]) + minCost(1,3,nums,n-2,dp);

        return min(n12,min(n23,n13));
    }
};