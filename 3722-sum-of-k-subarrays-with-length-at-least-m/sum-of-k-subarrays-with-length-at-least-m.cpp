class Solution {
public:
    vector<int> ps;
    int n;
    int dp[2001][2001][2];
    int f(int idx, int flag, int& m, int k, vector<int>& nums) {
        if (k < 0) return -1e9;
        if (idx >= n) return k == 0 ? 0 : -1e9;

        int ans = -1e9;
        if(dp[idx][k][flag]!=-1) return dp[idx][k][flag];
        if (flag) {
            ans = max(ans, nums[idx] + f(idx + 1, 1, m, k, nums));
            ans = max(ans, f(idx, 0, m, k, nums));
        } 
        else {
            int li = idx + m - 1;
            if (li < n) {
                ans = max(ans, ps[li + 1] - ps[idx] + f(li + 1, 1, m, k - 1, nums));
            }
            ans = max(ans, f(idx + 1, 0, m, k, nums));
        }

        return dp[idx][k][flag] = ans;
    }

    int maxSum(vector<int>& nums, int k, int m) {
        n = nums.size();
        ps.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }
        memset(dp,-1,sizeof(dp));
        return f(0, 0, m, k, nums);
    }
};