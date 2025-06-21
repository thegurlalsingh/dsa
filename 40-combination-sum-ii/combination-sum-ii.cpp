class Solution {
private:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& res, vector<int>& temp) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (i >= candidates.size() || candidates[i] > target) {
            return;
        }

        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, res, temp);
        temp.pop_back();

        int next = i + 1;
        while (next < candidates.size() && candidates[next] == candidates[i]) {
            next++;
        }
        solve(candidates, target, next, res, temp); 
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates, target, 0, res, temp);
        return res;
    }
};
