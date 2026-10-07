class Solution {
    int solve(int i , int del , vector<int>& nums , vector<vector<int>>& dp) {
        if(i == nums.size()) {
            return 0 ;
        }

        if(dp[i][del] != INT_MIN) {
            return dp[i][del] ;
        }

        int ans = 0 ;
        int val = nums[i];

        // Take current element
        int take = val + solve(i + 1 , del , nums , dp) ;
        ans = max(ans , take) ;

        // Delete current element
        if(del == 0) {
            int skip = solve(i + 1 , 1 , nums , dp) ;
            ans = max(ans , skip) ;
        }

        return dp[i][del] = ans ;
    }
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size() ;

        vector<vector<int>> dp(n + 1, vector<int>(2 , INT_MIN)) ;

        int ans = INT_MIN ;

        int i = 0 ;

        while(i < n) {
            int curr = arr[i] + solve(i + 1 , 0 , arr , dp) ;
            ans = max(ans , curr) ;
            i++ ;
        }

        return ans ;
    }
};