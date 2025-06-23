class Solution {
    bool isPalindrome(int start, int end, string &s) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool solve(int i, vector<vector<int>>& dp, int n, string& s, int k){
        if (i == n) {
            return k == 0;
        }
        if (k == 0) {
            return false; 
        }
        if (dp[i][k] != -1) {
            return dp[i][k]; 
        }

        bool possible = false;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) { 
                bool cost = solve(j + 1, dp, n, s, k - 1);
                if (cost) {                    
                    possible = true;
                    break;                     
                }
            }
        }
        return dp[i][k] = possible;
    }

public:
    bool checkPartitioning(string s) {
        int n = s.size();
        int k = 3;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
        return solve(0, dp, n, s, k);
    }
};
