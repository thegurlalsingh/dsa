class Solution {
    map<pair<int,int>, bool> dp;

    bool solve(int i, vector<int>& nums, int P, int n, set<int>& s) {
        if (nums[i] == nums.back())
            return true;

        if (dp.count({nums[i], P}))
            return dp[{nums[i], P}];

        bool ans = false;

        // jump = P - 1
        if (P - 1 > 0 && s.find(nums[i] + P - 1) != s.end()) {
            int nextIndex = lower_bound(nums.begin(), nums.end(), nums[i] + P - 1) - nums.begin();
            ans = ans || solve(nextIndex, nums, P - 1, n, s);
        }

        // jump = P
        if (P > 0 && s.find(nums[i] + P) != s.end()) {
            int nextIndex = lower_bound(nums.begin(), nums.end(), nums[i] + P) - nums.begin();
            ans = ans || solve(nextIndex, nums, P, n, s);
        }

        // jump = P + 1
        if (s.find(nums[i] + P + 1) != s.end()) {
            int nextIndex = lower_bound(nums.begin(), nums.end(), nums[i] + P + 1) - nums.begin();
            ans = ans || solve(nextIndex, nums, P + 1, n, s);
        }

        return dp[{nums[i], P}] = ans;
    }

public:
    bool canCross(vector<int>& stones) {
        set<int> s(stones.begin(), stones.end());
        if (stones[1] != 1) return false; // must start with jump 1
        return solve(1, stones, 1, stones.size(), s);
    }
};
