class Solution {
    void solve(vector<vector<int>>& res, vector<int>& curr, int k, int n, int start, int sum) {
        if (sum == n) {
            if(curr.size() == k){
                res.push_back(curr);
                return;
            }
        }

        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            solve(res, curr, k, n, i + 1, sum + i); 
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(res, curr, k, n, 1, 0);
        return res;
    }
};