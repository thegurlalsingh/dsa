class Solution {
    void solve(vector<vector<int>>& res, vector<int> curr, vector<int>& candidates, int target, int i, int sum){
        if(sum == target){
            res.push_back(curr);
            return ;
        }
        if(i >= candidates.size()){
            return ;
        }
        if(sum + candidates[i] <= target){
            curr.push_back(candidates[i]);
            solve(res, curr, candidates, target, i, sum + candidates[i]);
            curr.pop_back();
        }
        solve(res, curr, candidates, target, i + 1, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(res, curr, candidates, target, 0, 0);
        return res;
    }
};