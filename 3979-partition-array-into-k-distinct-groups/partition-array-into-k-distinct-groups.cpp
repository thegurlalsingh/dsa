class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size() % k != 0) {
            return false;
        }

        unordered_map<int,int> freq;
        int x = nums.size() / k;

        for(auto a : nums){
            freq[a]++;
            if(freq[a] > x) {
                return false; 
            }
        }

        return true;
    }
};