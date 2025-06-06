class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                if (cnt > 1)
                    return false;
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
            }
        }
        return true;
    }
};