class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXor;
        
        // Step 1: all pair XORs
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> ans;

        // Step 2: extend to triplets
        for(auto& val : pairXor){
            for(int i = 0; i < nums.size(); i++){
                ans.insert(val ^ nums[i]);
            }
        }

        return ans.size();
    }
};