class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int n = nums.size();
        int leftmost = -1;
        int mini = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (leftmost == -1) {
                    leftmost = i;
                    sum = 0;
                    mini = INT_MAX;
                }
                sum += nums[i];
                mini = min(mini, nums[i]);
            }
            else {
                if (leftmost != -1) {
                    ans += sum;
                    if (leftmost > 0) {
                        ans += max(0, nums[leftmost - 1] - mini);
                    }
                    leftmost = -1;
                    mini = INT_MAX;
                    sum = 0;
                }
            }
        }
        if (leftmost != -1) {
            ans += sum;
            if (leftmost > 0) {
                ans += max(0, nums[leftmost - 1] - mini);
            }
        }
        return ans;
    }
};