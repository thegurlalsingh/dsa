class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));

        // Precompute right and down arrays
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = (j == m - 1) ? 1 : 1 + right[i][j + 1];
                    down[i][j] = (i == n - 1) ? 1 : 1 + down[i + 1][j];
                }
            }
        }

        int maxsize = 0;

        // Iterate to find the largest square
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int maxside = min(right[i][j], down[i][j]);

                for (int side = maxside; side > maxsize; side--) { // Early stopping
                    if (right[i + side - 1][j] >= side && down[i][j + side - 1] >= side) {
                        maxsize = side;
                        break;  // No need to check smaller sizes
                    }
                }
            }
        }
        return maxsize * maxsize;
    }
};