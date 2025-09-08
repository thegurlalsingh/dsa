class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        int rows = mat.size();
        if (rows == 0) return 0;
        int cols = mat[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                }
                maxArea = max(maxArea, dp[i][j] * dp[i][j]);
            }
        }
        
        return maxArea;
    }
};