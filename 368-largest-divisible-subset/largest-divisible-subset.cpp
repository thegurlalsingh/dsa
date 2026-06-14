class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int maxLen = 1;
        int lastIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;

        while (lastIdx != -1) {
            ans.push_back(nums[lastIdx]);
            lastIdx = parent[lastIdx];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};