class Solution {
    long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp) {
        if (i >= questions.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        long long skip = solve(i + 1, questions, dp);
        long long take = questions[i][0] + solve(i + questions[i][1] + 1, questions, dp); // dont forget + 1 as you have to skip brainpower_i indexes and yes no need of condition of if, as base case already handles it

        return dp[i] = max(take, skip);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), (long long)-1);
        return solve(0, questions, dp);
    }
};