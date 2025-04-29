class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        long long count = 0;
        unordered_map<long long, long long> m;
        int n = nums.size();
        while(j < n){
            m[nums[j]]++;
            while(m[maxi] >= k){
                count += (n - j);
                m[nums[i]]--;
                if(m[nums[i]] == 0){
                    m.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};