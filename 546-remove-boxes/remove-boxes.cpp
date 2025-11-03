class Solution {
    int memo[100][100][100];

public:
    int solve(vector<int>& boxes, int i, int j, int k) {
        if (i > j)
            return 0;
        if (memo[i][j][k] != -1)
            return memo[i][j][k];
        // Count consecutive boxes with same color as boxes[i]
        int cnt = 0;
        while (i + cnt <= j && boxes[i + cnt] == boxes[i]) {
            cnt++;
        }

        // Option 1: Remove current group immediately
        int result = (k + cnt) * (k + cnt) + solve(boxes, i + cnt, j, 0);

        // Option 2: Try merging with later matching boxes
        for (int m = i + 1; m <= j; ++m) {
            if (boxes[i] == boxes[m]) {
                int take = solve(boxes, i + 1, m - 1, 0) + solve(boxes, m, j, k + 1);
                result = max(take, result);
            }
        }
        return memo[i][j][k] = result;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(memo, -1, sizeof memo);
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};