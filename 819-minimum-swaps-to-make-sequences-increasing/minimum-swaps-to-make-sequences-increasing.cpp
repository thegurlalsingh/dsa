class Solution {
    int solve(int i, bool swapped, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i == nums1.size()) return 0;

        if(dp[i][swapped] != -1) return dp[i][swapped];

        int prev1 = nums1[i - 1];
        int prev2 = nums2[i - 1];

        if(swapped) swap(prev1, prev2);

        int ans = 1e9;

        // Option 1: don't swap
        if(nums1[i] > prev1 && nums2[i] > prev2)
            ans = solve(i + 1, false, nums1, nums2, dp);

        // Option 2: swap
        if(nums1[i] > prev2 && nums2[i] > prev1)
            ans = min(ans, 1 + solve(i + 1, true, nums1, nums2, dp));

        return dp[i][swapped] = ans;
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(1, false, nums1, nums2, dp);
    }
};
