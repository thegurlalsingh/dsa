class Solution {
public:
    vector<int> dp; // -1 --> not touched yet, 0 --> loss state, 1 --> win state

    // Recursive function to determine if the current state is a winning state
    int f(int n) {
        if (n < 0) return 0;
        // If DP already evaluated the state, then return the state
        if (dp[n] != -1) return dp[n];
        // Finding if it's a win or loss state
        for (int i = 1; i * i <= n; i++) {
            if (f(n - i * i) == 0) {
                return dp[n] = 1; 
            }
        }
        // Didn't find any winning state, return that it's a loss state
        return dp[n] = 0;
    }

    bool winnerSquareGame(int n) {
        // Initializing DP
        dp.clear();
        dp.resize(n + 1, -1);
        // 0th state is a loss one
        dp[0] = 0;
        return f(n);
    }
};