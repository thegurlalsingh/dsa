class Solution {
private:
    int mismatches(int start, int end, string &s) {
        int mismatches = 0;
        while (start < end) {
            if (s[start] != s[end]) {
                mismatches++;
            }
            start++;
            end--;
        }
        return mismatches;
    }

    int solve(string& s, int k, int i, vector<vector<int>> &dp, int n){
        if(i >= s.length() && k == 0){
            return 0;
        }
        if(k == 0 || i >= s.length()){
            return INT_MAX;
        }
        if (dp[i][k] != -1) {
            return dp[i][k]; 
        }
        int changes = INT_MAX;
        for (int j = i; j < n; j++) {
            int cost = mismatches(i, j, s);
            int next = solve(s, k - 1, j + 1, dp, n);
            if(next != INT_MAX){
                changes = min(changes, cost + next);
            }
        }
        return dp[i][k] = changes; 

    }
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
        int result = solve(s, k, 0, dp, n);
        return result == INT_MAX ? 0 : result;
    }
};