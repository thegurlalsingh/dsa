class Solution {
    vector<int> solve(int i, int prev, vector<int>& nums, vector<int>& parent) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            for (int j = 0; j < i; j++) {
                if (((nums[j] % nums[i] == 0) || (nums[i] % nums[j] == 0)) && dp[j] + 1 > dp[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    parent[i] = j;
                }
            }
        }
        return dp;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> parent(nums.size(), -1);
        vector<int> dp = solve(0, -1, nums, parent);
        int peakElem = -1; int peak = -1;
        for(int i = 0; i < dp.size(); i++){
            if(dp[i] > peakElem){
                peakElem = dp[i];
                peak = i;
            }
            else if(dp[i] == peakElem){
                peak = i;
            }
        }

        vector<int> ans;
        while(peak != -1){
            ans.push_back(nums[peak]);
            peak = parent[peak];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};