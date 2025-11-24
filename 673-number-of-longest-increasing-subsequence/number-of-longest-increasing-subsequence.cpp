class Solution {
    vector<vector<int>> memo;   // memo[start][P]

    int h(vector<int>& nums, vector<int>& dp, int start, int P) {
        if (P >= 0 && dp[P] == 1) return 1;
        if (start < 0) return 0;

        if (memo[start][P] != -1) return memo[start][P];

        int ways = 0;

        // skip
        ways += h(nums, dp, start - 1, P);

        // take
        if (nums[start] < nums[P] && dp[start] == dp[P] - 1) {
            ways += h(nums, dp, start - 1, start);
        }

        return memo[start][P] = ways;
    }

    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);
        int maxL = 1;

        // LIS dp
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxL = max(maxL, dp[i]);
        }

        // memo size: start from 0..n-1 and P from 0..n-1
        memo.assign(n, vector<int>(n, -1));

        int total = 0;

        // count LIS ending at each index with dp[i] == maxL
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxL) {
                total += h(nums, dp, i - 1, i);
            }
        }

        return total;
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        return helper(nums);
    }
};
