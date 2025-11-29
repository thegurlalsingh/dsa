class Solution {
public:
    vector<vector<int>> cost;               // cost to make s[l..r] palindrome
    int n;
    string s;
    int dp[101][101];                       // dp[idx][k]

    // Cost to convert s[l..r] into palindrome
    int getCost(int l, int r) {
        int cnt = 0;
        while (l < r) {
            if (s[l] != s[r]) cnt++;
            l++; r--;
        }
        return cnt;
    }

    // Recursively split s[idx..n-1] into k palindromes
    int solve(int idx, int k) {
        if (idx == n && k == 0) return 0;
        if (idx == n || k == 0) return 1e9;   // invalid
        if (dp[idx][k] != -1) return dp[idx][k];

        int ans = 1e9;

        // Try ending the first palindrome at every position i
        for (int i = idx; i < n; i++) {
            int partCost = cost[idx][i];               // make s[idx..i] palindrome
            ans = min(ans, partCost + solve(i + 1, k - 1));
        }

        return dp[idx][k] = ans;
    }

    int palindromePartition(string s, int k) {
        this->s = s;
        n = s.size();

        memset(dp, -1, sizeof(dp));
        cost.assign(n, vector<int>(n, 0));

        // Precompute cost for every substring
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cost[i][j] = getCost(i, j);
            }
        }

        return solve(0, k);
    }
};
