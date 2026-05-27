class Solution {
    void solve(int i, vector<int> &current, vector<vector<int>>& ans, vector<int>& nums){
        if(!current.empty()){
            ans.push_back(current);
        }

        for(int j = i; j < nums.size(); j++){
            current.push_back(nums[j]);
            solve(j + 1, current, ans, nums);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> ans;
        ans.push_back({});
        solve(0, current, ans, nums);
        return ans;
    }
};