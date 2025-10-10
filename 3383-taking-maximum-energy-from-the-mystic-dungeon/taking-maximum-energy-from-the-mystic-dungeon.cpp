class Solution {
    int solve(int i, vector<int>& energy, int k, vector<int>& dp) {
        if (i >= energy.size()) return 0;
        if (dp[i] != INT_MIN) return dp[i];
        return dp[i] = energy[i] + solve(i + k, energy, k, dp);
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, energy, k, dp));
        }
        return ans;
    }
};
