class Solution {
    int solve(int i, vector<int>& stones, int sum, int total, vector<vector<int>>& dp){
        if(i >= stones.size()){
            return abs(total - 2 * sum);
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int skip = solve(i + 1, stones, sum, total, dp);
        int take = solve(i + 1, stones, sum - stones[i], total, dp);
        return dp[i][sum] = min(take, skip);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size(), vector<int>(3001, -1)); // 30 length and if everyone is 100
        return solve(0, stones, sum, sum, dp);
    }
};