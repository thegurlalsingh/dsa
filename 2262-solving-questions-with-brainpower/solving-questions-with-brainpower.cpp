class Solution {
private:
    vector<long long> dp;

    long long solve(int idx, vector<vector<int>>& questions) {
        if (idx >= questions.size()) {
            return 0;
        }
        if (dp[idx] != -1) { 
            return dp[idx];
        }

        long long take = questions[idx][0] + solve(idx + questions[idx][1] + 1, questions);        
        long long skip = solve(idx + 1, questions);        
        return dp[idx] = max(take, skip);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(), -1);
        return solve(0, questions);
    }
};
