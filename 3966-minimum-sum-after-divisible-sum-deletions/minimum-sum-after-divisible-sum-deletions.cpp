class Solution {
public:
    long long solve(int i, vector<int>& nums, int k, int sum,
                    unordered_map<int,int>& mp, vector<long long>& dp) {

        int n = nums.size();
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        sum = (sum + nums[i]) % k;

        long long ans = nums[i] + solve(i + 1, nums, k, sum, mp, dp);

        if(mp.count(sum)) {
            ans = min(ans, dp[mp[sum]]);
        }

        mp[sum] = i;

        return dp[i] = ans;
    }

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