class Solution {
    long long cost(int mini, int maxi, int l, int r) {
        long long diff = (long long)maxi - mini;
        long long len  = (long long)r - l + 1;
        return diff * len;
    }
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0; int j = 0; long long count = 0; int n = nums.size(); map<int, int> mp;
        while(j < n){
            mp[nums[j]]++;
            auto itFirst = mp.begin(); auto itLast = prev(mp.end()); 
            long long c = cost(itFirst->first, itLast->first, i, j);
            while(c > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
                itFirst = mp.begin(); itLast = prev(mp.end()); 
                c = cost(itFirst->first, itLast->first, i, j);
            } 
            count += j - i + 1;
            j++;
        }
        return count;
    }
};