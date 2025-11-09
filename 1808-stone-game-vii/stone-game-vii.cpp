class Solution {
public:
    int solve(int i, int j, vector<int>& stones, vector<int>& prefix, vector<vector<int>>& dp) {
        if (i == j) return 0; // no stones left to remove → no score
        if (dp[i][j] != -1) return dp[i][j];

        int total = prefix[j + 1] - prefix[i]; // sum(i, j)
        int leftGain = total - stones[i] - solve(i + 1, j, stones, prefix, dp); // remove left
        int rightGain = total - stones[j] - solve(i, j - 1, stones, prefix, dp); // remove right

        return dp[i][j] = max(leftGain, rightGain);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, stones, prefix, dp);
    }
};
