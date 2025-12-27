class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        vector<int> r(n,1), l(n,1);
        
        for(int i = 1 ; i < n; i++)
            if(nums[i-1] <= nums[i]) l[i] += l[i-1];
        
        for(int i = n -2 ; i >= 0; i--)
            if(nums[i+1] >= nums[i]) r[i] += r[i+1];
        
        int ans= max(l[0], r[n-1]);
        for(int i = 1; i < n -1; i++) {
            if(nums[i-1] <= nums[i+1])
                ans=max({ans, l[i-1] + r[i+1] +1});
            else ans=max({ans, l[i] + 1, r[i] +1});
        }

        return ans;
    }
};