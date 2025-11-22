class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // prefix from left
        vector<int> left(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            left[i] = left[i - 1] + cardPoints[i - 1];
        }

        // prefix from right
        vector<int> right(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            right[i] = right[i - 1] + cardPoints[n - i];
        }

        int ans = 0;

        // try all splits: i from left, k-i from right
        for (int i = 0; i <= k; i++) {
            ans = max(ans, left[i] + right[k - i]);
        }

        return ans;
    }
};
