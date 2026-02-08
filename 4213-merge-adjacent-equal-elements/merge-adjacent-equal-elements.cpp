class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;
        if (nums.empty()){
            return res;
        }
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            long long cur = nums[i];
            while (!res.empty() && res.back() == cur) {
                res.pop_back();   
                cur *= 2;         
            }
            res.push_back(cur);
        }
        return res;
    }
};
