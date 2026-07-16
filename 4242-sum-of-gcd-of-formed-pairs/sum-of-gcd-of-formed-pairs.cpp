class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> maxi(nums.size(), 0), prefixGcd(nums.size(), 0);
        maxi[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxi[i] = max(maxi[i - 1], (long long)nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            prefixGcd[i] = gcd(maxi[i], nums[i]);
        }
        long long sum = 0;
        sort(prefixGcd.begin(), prefixGcd.end());
        for(int i = 0; i < nums.size() / 2; i++){
            sum += gcd(prefixGcd[i] , prefixGcd[nums.size() - i - 1]);
        }
        return sum;
    }
};