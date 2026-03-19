class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return 1LL * nums[n - 1] * nums[n - 2] * 100000;
    }
};