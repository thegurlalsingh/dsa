const int MOD = 1e9 + 7;
class Solution {
    pair<int, int> solve(int i, int j, vector<vector<pair<int, int>>>& dp,
                         vector<vector<int>>& matrix,
                         vector<vector<int>>& vis) {
        if (i == 0 && j == 0) {
            return {0, 1};
        }
        if (vis[i][j]) {
            return dp[i][j];
        }
        vis[i][j] = 1;
        pair<int, int> up = {INT_MIN, 0};
        pair<int, int> left = {INT_MIN, 0};
        pair<int, int> up_left = {INT_MIN, 0};
        if (i - 1 >= 0 && matrix[i - 1][j] != INT_MIN) {
            up = solve(i - 1, j, dp, matrix, vis);
            if (up.first != INT_MIN) {
                up.first += matrix[i][j];
            }
        }
        if (j - 1 >= 0 && matrix[i][j - 1] != INT_MIN) {
            left = solve(i, j - 1, dp, matrix, vis);
            if (left.first != INT_MIN) {
                left.first += matrix[i][j];
            }
        }
        if (j - 1 >= 0 && i - 1 >= 0 && matrix[i - 1][j - 1] != INT_MIN) {
            up_left = solve(i - 1, j - 1, dp, matrix, vis);
            if (up_left.first != INT_MIN) {
                up_left.first += matrix[i][j];
            }
        }

        vector<pair<int, int>> choices;

        choices.push_back(left);
        choices.push_back(up);
        choices.push_back(up_left);

        int best_len = INT_MIN;
        int ways = 0;

        for (auto [len, cnt] : choices) {
            if (len > best_len) {
                best_len = len;
                ways = cnt;
            } else if (len == best_len) {
                ways = (ways + cnt) % MOD;
            }
        }

        return dp[i][j] = {best_len, ways};
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        vector<vector<pair<int, int>>> dp(m,
                                          vector<pair<int, int>>(n, {-1, -1}));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'S') {
                    matrix[i][j] = 0;
                } else if (board[i][j] == 'E') {
                    matrix[i][j] = 0;
                } else if (board[i][j] == 'X') {
                    matrix[i][j] = INT_MIN;
                } else {
                    matrix[i][j] = board[i][j] - '0';
                }
            }
        }
        pair<int, int> ans = solve(m - 1, n - 1, dp, matrix, vis);
        return {ans.first == INT_MIN ? 0 : ans.first, ans.second};
    }
};