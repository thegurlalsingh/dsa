class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;  
        
        unordered_map<int, int> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int val = i - nums[i];
            if (freq.find(val) != freq.end()) {
                goodPairs += freq[val]; 
            }
            freq[val]++;  
        }
        
        return totalPairs - goodPairs;
    }
};