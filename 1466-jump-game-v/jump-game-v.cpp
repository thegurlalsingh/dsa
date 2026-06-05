class Solution {
    int solve(int idx, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[idx] != -1) {
            return dp[idx];
        } // no base case needed in this case because A node with no valid jumps
          // should simply return 1.

        int ans = 1; // current node is counted as one position
        for (int i = 1; i <= d; i++) {

            if (idx + i >= arr.size())
                break;

            if (arr[idx + i] >= arr[idx])
                break;

            if (i + idx < arr.size() && arr[idx] > arr[i + idx]) {
                ans = max(ans, 1 + solve(idx + i, arr, d, dp));
            }
        }

        for (int i = 1; i <= d; i++) {
            if (idx - i < 0)
                break;

            if (arr[idx - i] >= arr[idx])
                break;

            if (idx - i >= 0 && arr[idx] > arr[idx - i]) {
                ans = max(ans, 1 + solve(idx - i, arr, d, dp));
            }
        }

        return dp[idx] = ans;
        ;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int ans = 1;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, solve(i, arr, d, dp));
        }
        return ans;
    }
};