class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i += 3){
            vector<int> t;
            t.push_back(nums[i]);
            for(int j = i + 1; j < i + 3; j++){
                if(nums[j] - nums[i] <= k){
                    t.push_back(nums[j]);
                } 
                else {
                    return {};
                }
            }
            arr.push_back(t);
        }

        return arr;
    }
};
