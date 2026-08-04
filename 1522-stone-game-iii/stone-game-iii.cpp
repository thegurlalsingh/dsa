class Solution {
    int solve(int i, vector<int>& dp, vector<int>& stoneValue,
              vector<int>& visited) {
        if (i >= stoneValue.size()) {
            return 0;
        }
        if (visited[i]) {
            return dp[i];
        }
        int ans = INT_MIN;
        int one = INT_MIN, two = INT_MIN, three = INT_MIN;

        one =
            stoneValue[i] -
            solve(
                i + 1, dp, stoneValue,
                visited); // we are just subtracting the recrusive function
                          // because the only thing which matters is
                          // prespective, for example in current situation we
                          // are thinking that next is bob so we are
                          // subtracting, good but when bob's turn will come so
                          // from his prespective alice is opponent so she
                          // should subtract the score more so that bob can have
                          // higher score.... thing is all about prespective,
                          // whoever is at current index will try to maximize
                          // their score and thus subtract opponent score

        if (i + 1 < stoneValue.size()) {
            two = stoneValue[i] + stoneValue[i + 1] -
                  solve(i + 2, dp, stoneValue, visited);
        }

        if (i + 2 < stoneValue.size()) {
            three = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                    solve(i + 3, dp, stoneValue, visited);
        }
        ans = max(ans, one);
        ans = max(ans, two);
        ans = max(ans, three);
        // ans = max(ans, max({one, two, three}));
        visited[i] = 1;
        return dp[i] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);
        vector<int> visited(stoneValue.size(), 0);
        int s = solve(
            0, dp, stoneValue,
            visited); // just going with one state ie index because if we will
                      // take chance state too with 0 and 1 then it can link to
                      // that bob can have first chance which is against
                      // question because alice will always have first chance

        if (s > 0) {
            return "Alice";
        } else if (s < 0) {
            return "Bob";
        }
        return "Tie";
    }
};