class Solution {
    int dfs(int i, int n, vector<int> &nums, unordered_map<int, int> &m, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int notpick = 0 + dfs(i + 1, n, nums, m, dp);
        int pick = m[nums[i]] * nums[i];
        if(i + 1 < n && nums[i] + 1 == nums[i + 1]) pick += dfs(i + 2, n, nums, m, dp);
        else if(i + 1 < n && nums[i] + 1 != nums[i + 1]) pick += dfs(i + 1, n, nums, m, dp);
        
        return dp[i] = max(pick, notpick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) m[i]++;

        vector<int> v;
        for(auto i : m) v.push_back(i.first);
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> dp(n, -1);

        return dfs(0, n, v, m, dp);
    }
};