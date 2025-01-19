class Solution {
private:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0; 
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; 
        }

        if (matrix[i][j] == 0) {
            return dp[i][j] = 0; 
        }
        int top = solve(matrix, i - 1, j, dp);
        int left = solve(matrix, i, j - 1, dp);
        int dia = solve(matrix, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min({top, left, dia});
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> newmatrix(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                newmatrix[i][j] = matrix[i][j] - '0';
            }
        }

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int maxSize = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxSize = max(maxSize, solve(newmatrix, i, j, dp)); 
            }
        }

        return maxSize * maxSize; 
    }
};
