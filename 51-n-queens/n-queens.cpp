class Solution {
    vector<vector<string>> solutions;
    vector<string> board;

    void backtrack(int n, int row, unordered_set<int>& cols,
                   unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue; // not safe
            }

            // place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(n, row + 1, cols, diag1, diag2);

            // backtrack
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        unordered_set<int> cols, diag1, diag2;
        backtrack(n, 0, cols, diag1, diag2);
        return solutions;
    }
};
