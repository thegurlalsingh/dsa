class Solution {
public:
    pair<int, int> helper(vector<int>& nums, int i, int& ans) {
    if (i == 0) {
        ans = max(ans, nums[0]);
        return {nums[0], nums[0]}; // {maxProd, minProd} at index 0
    }

    auto [prevMax, prevMin] = helper(nums, i - 1, ans);

    int cur1 = nums[i];
    int cur2 = nums[i] * prevMax;
    int cur3 = nums[i] * prevMin;

    int curMax = max({cur1, cur2, cur3});
    int curMin = min({cur1, cur2, cur3});

    ans = max(ans, curMax);

    return {curMax, curMin};
}

int maxProduct(vector<int>& nums) {
    int ans = INT_MIN;
    helper(nums, nums.size() - 1, ans);
    return ans;
}

};