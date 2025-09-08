#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<vector<char>>& board, string& word, int i, int x, int y) {
        // if we matched all characters
        if (i == word.size()) {
            return true;
        }

        // out of bounds
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }

        // mismatch
        if (board[x][y] != word[i]) {
            return false;
        }

        // mark visited
        char temp = board[x][y];
        board[x][y] = '#';

        // explore neighbors
        bool found = solve(board, word, i + 1, x + 1, y) ||
                     solve(board, word, i + 1, x - 1, y) ||
                     solve(board, word, i + 1, x, y + 1) ||
                     solve(board, word, i + 1, x, y - 1);

        // backtrack
        board[x][y] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && solve(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
