class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        mp[0] = n;

        vector<long long> dp(n+1, -1);
        dp[n] = 0;

        int sum = 0;

        for(int i = n-1; i >= 0; i--) {
            sum = (sum + nums[i]) % k;

            dp[i] = nums[i] + dp[i+1];

            if(mp.count(sum)) {
                dp[i] = min(dp[i], dp[mp[sum]]);
            }

            mp[sum] = i;
        }

        return dp[0];
    }
};