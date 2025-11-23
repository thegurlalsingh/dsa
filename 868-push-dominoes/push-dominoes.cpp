class Solution {
public:
    string pushDominoes(string s) {
    int N = s.size(), right = -1;

    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            if (right == -1) { 
                // No unmatched R before → push all dots to the left
                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                    s[j] = 'L';
                }
            } else {
                // There was R ... L → fill from both sides
                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                    s[j] = 'R';
                    s[k] = 'L';
                }
                right = -1;  // Clear unmatched R
            }
        } 
        else if (s[i] == 'R') {
            if (right != -1) {
                // Previous R exists → fill all dots with R
                for (int j = right + 1; j < i; ++j) s[j] = 'R';
            }
            right = i; // Set current R as unmatched
        }
    }

    // After full scan, if the last force is R → push right till end
    if (right != -1) {
        for (int j = right + 1; j < N; ++j) s[j] = 'R';
    }

    return s;
}

};