class Solution {
public:
    vector<vector<int>> dp;
    const int NEG = -1000000000; // safe large negative sentinel

    int solve(int i, int j, vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (i >= n || j >= m) return NEG;   // cannot form a pair -> very negative

        if (dp[i][j] != NEG) return dp[i][j];

        // take this pair; if continuation is negative, stop after this pair (hence max(0, ...))
        int take = a[i] * b[j];
        int cont = solve(i + 1, j + 1, a, b);
        if (cont > 0) take += cont;

        // skip options
        int skip1 = solve(i + 1, j, a, b);
        int skip2 = solve(i, j + 1, a, b);

        return dp[i][j] = max({ take, skip1, skip2 });
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        dp.assign(n, vector<int>(m, NEG));

        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, solve(i, j, nums1, nums2));
            }
        }
        return ans;
    }
};
