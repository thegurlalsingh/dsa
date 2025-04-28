class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0LL;
        vector<long long> prefix(n + 1, 0LL);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int i = 0;
        int j = 0;
        while (j < n) {
            while (i <= j && (prefix[j + 1] - prefix[i]) * (j - i + 1) >= k) {
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        
        return ans;
    }
};
