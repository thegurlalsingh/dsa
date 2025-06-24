class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> result;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if((abs(i - j) <= k) && (nums[j] == key)){
                    result.insert(i);
                    break;
                }
            }
        }
        vector<int> r(result.begin(), result.end());
        return r;
    }
};