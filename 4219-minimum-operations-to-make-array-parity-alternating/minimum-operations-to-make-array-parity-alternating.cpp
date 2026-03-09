
class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        if (nums.size() == 1) return {0, 0};
        
        int zero = 0, one = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) != (i & 1)) zero++;
            if ((nums[i] & 1) != ((i + 1) & 1)) one++;
        }
        
        vector<int> ans(2);
        ans[0] = min(one, zero);
        
        if (one == zero) ans[1] = min(fun(nums, 0), fun(nums, 1));
        else if (one > zero) ans[1] = fun(nums, 0);
        else ans[1] = fun(nums, 1);
        
        return ans;
    }
    
private:
    int fun(vector<int>& nums, int parity) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) == ((i + parity) & 1)) {
                maxVal = max(maxVal, nums[i]);
                minVal = min(minVal, nums[i]);
            } else {
                maxVal = max(maxVal, nums[i] - 1);
                minVal = min(minVal, nums[i] + 1);
            }
        }
        return max(maxVal - minVal, 1);
    }
};