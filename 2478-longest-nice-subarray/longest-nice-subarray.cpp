class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0;         
        int maxlen = 0;    
        int current_mask = 0;  
        for (int j = 0; j < nums.size(); ++j) {
            while ((current_mask & nums[j]) != 0) {
                current_mask ^= nums[i];  
                i++;  
            }            
            current_mask |= nums[j];            
            maxlen = max(maxlen, j - i + 1);
        }
        
        return maxlen;
    }
};
