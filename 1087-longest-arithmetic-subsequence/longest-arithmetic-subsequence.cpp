class Solution {
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 0;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            ans = max(ans, dp[x]);
        }
        return ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        set<int> diff;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                diff.insert(nums[j] - nums[i]);
            }
        }
        int ans = INT_MIN;
        for (int x : diff) {
            ans = max(ans, longestSubsequence(nums, x));
        }
        return ans;
    }
};