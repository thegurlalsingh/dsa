class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        // using map here because finding in map is easy
        vector<unordered_map<int, int>> dp(n);

        int ans = 2; // any two elements can always form an arithmetic subsequence.

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j]; // calculate diff
                int len = 2;
                // Is there any arithmetic subsequence ending at index j with difference diff. If yes then attach current index i element to that and increase the len
                if(dp[j].count(diff)) {
                    len = dp[j][diff] + 1;
                }
                // as multiple prev element j can lead to same i and diff, thus we will update diff because we can have greater len
                dp[i][diff] = max(dp[i][diff], len);

                // greater len is ans
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};