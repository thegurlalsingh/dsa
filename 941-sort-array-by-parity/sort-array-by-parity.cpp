class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                m[0].push_back(nums[i]);
            }
            else{
                m[1].push_back(nums[i]);
            }
        }
        vector<int> res = m[0];
        for(int i = 0; i < m[1].size(); i++){
            res.push_back(m[1][i]);
        }
        return res;
    }
};