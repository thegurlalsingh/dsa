class Solution {
public:
    int n, m;
    vector<int> a, b;
    const long long NEG = -1e18;

    vector<vector<vector<long long>>> dp;
    vector<vector<vector<char>>> vis;

    long long dfs(int i, int j, int t) {
        if (t == 0) return 0;
        if (i == n || j == m) return NEG;
        if (n - i < t || m - j < t) return NEG;

        if (vis[i][j][t]) return dp[i][j][t];
        vis[i][j][t] = 1;

        long long take = 1LL * a[i] * b[j] + dfs(i + 1, j + 1, t - 1);
        long long skip1 = dfs(i + 1, j, t);
        long long skip2 = dfs(i, j + 1, t);

        return dp[i][j][t] = max({take, skip1, skip2});
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();

        dp.assign(n, vector<vector<long long>>(m, vector<long long>(k + 1, 0)));
        vis.assign(n, vector<vector<char>>(m, vector<char>(k + 1, 0)));

        return dfs(0, 0, k);
    }
};
