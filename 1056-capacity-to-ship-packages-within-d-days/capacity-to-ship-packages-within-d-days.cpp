class Solution {
    bool check(int cap, vector<int>& weights, int days) {
        int d = 1;
        long long curr = 0;
        for (int w : weights) {
            if (w > cap)
                return false;
            if (curr + w <= cap) {
                curr += w;
            } else {
                d++;
                curr = w;
            }
        }
        return d <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int i = 1;
        int j = 1e9;
        int ans = 0;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (check(mid, weights, days)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};