class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp;
    unordered_map<int, vector<int>> moves = {
        {0,{4,6}}, {1,{6,8}}, {2,{7,9}}, {3,{4,8}},
        {4,{0,3,9}}, {5,{}},  {6,{0,1,7}}, {7,{2,6}},
        {8,{1,3}},  {9,{2,4}}
    };
    
    long long solve(int digit, int k) {
        if (k == 1) return 1; 
        if (dp[digit][k] != -1) return dp[digit][k];
        
        long long ways = 0;
        for (int nxt : moves[digit]) {
            ways = (ways + solve(nxt, k - 1)) % MOD;
        }
        return dp[digit][k] = ways;
    }
    
public:
    int knightDialer(int n) {
        dp.assign(10, vector<long long>(n + 1, -1));
        long long ans = 0;
        for (int d = 0; d <= 9; d++) {
            ans = (ans + solve(d, n)) % MOD;
        }
        return ans;
    }
};
