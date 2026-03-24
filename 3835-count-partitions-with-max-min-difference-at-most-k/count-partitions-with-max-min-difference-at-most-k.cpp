class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0), pref(n + 2, 0);
        dp[0] = 1;
        pref[1] = 1;

        deque<int> maxdq, mindq;
        int l = 0;

        for (int r = 0; r < n; r++) {
            // maintain max deque
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r])
                maxdq.pop_back();
            maxdq.push_back(r);

            // maintain min deque
            while (!mindq.empty() && nums[mindq.back()] >= nums[r])
                mindq.pop_back();
            mindq.push_back(r);

            // shrink window if invalid
            while (nums[maxdq.front()] - nums[mindq.front()] > k) {
                if (maxdq.front() == l) maxdq.pop_front();
                if (mindq.front() == l) mindq.pop_front();
                l++;
            }

            // dp transition
            dp[r + 1] = (pref[r + 1] - pref[l] + MOD) % MOD;

            // update prefix
            pref[r + 2] = (pref[r + 1] + dp[r + 1]) % MOD;
        }

        return dp[n];
    }
};