class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        // Compute normal row prefix sums (no extra 0 padding)
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            prefix[i][0] = matrix[i][0];
            for (int j = 1; j < n; j++) {
                prefix[i][j] = prefix[i][j-1] + matrix[i][j];
            }
        }

        // Fix left and right column boundaries
        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {

                unordered_map<int,int> freq;
                int cur = 0;

                for (int row = 0; row < m; row++) {
                    // sum of elements in this row between left and right
                    int rowSum = prefix[row][right] - (left > 0 ? prefix[row][left-1] : 0);
                    cur += rowSum;

                    // Check if the subarray starting from row 0 sums to target
                    if (cur == target) ans++;

                    // Check for subarrays ending at current row
                    if (freq.count(cur - target))
                        ans += freq[cur - target];

                    // Update frequency map
                    freq[cur]++;
                }
            }
        }

        return ans;
    }
};
