class Solution {
    vector<vector<long long>> dp;

    long long solve(int i, int j, string& s, string& t){
        if (j == t.length()) return 1;     // reached full t → valid subsequence
        if (i == s.length()) return 0;     // s finished but t not done
        
        if (dp[i][j] != -1) return dp[i][j];

        long long notTake = solve(i + 1, j, s, t);
        long long take = 0;

        if (s[i] == t[j]) {
            take = solve(i + 1, j + 1, s, t);
        }

        return dp[i][j] = take + notTake;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0, s, t);
    }
};
