class Solution {
    void solve(int open, int close, string current, vector<string>& res, int n){
        if(current.size() == n * 2){
            res.push_back(current);
            return ;
        }
        if(open < n){
            solve(open + 1, close, current + '(', res, n);
        }
        if(close < open){
            solve(open, close + 1, current + ')', res, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string current = "";
        vector<string> res;
        solve(0, 0, current, res, n);
        return res;
    }
};