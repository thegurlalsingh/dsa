#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int target, int i, long long eval) {
        if (i == nums.size()) {
            return (eval == target) ? 1 : 0;
        }

        // Try adding and subtracting nums[i]
        int add = solve(nums, target, i + 1, eval + nums[i]);
        int sub = solve(nums, target, i + 1, eval - nums[i]);

        return add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};
