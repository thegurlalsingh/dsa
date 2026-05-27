class Solution {
    void solve(int i, vector<int>& current, vector<vector<int>>& ans, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (i >= candidates.size() || target < 0) {
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            current.push_back(candidates[j]);
            solve(j, current, ans, candidates, target - candidates[j]);
            current.pop_back(); // stay at same place as we can reuse it, dont use accumulate as it is expensive, add one condition if sum goes below zero thats it
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        solve(0, current, ans, candidates, target);
        return ans;
    }
};