class Solution {
    bool isPalindrome(int x, int y, string s){
        while(x < y){
            if(s[x] != s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }


    void solve(vector<string>& current, vector<vector<string>>& res, string& s, int i, string t){
        if(i == s.size()){
            res.push_back(current);
            return;
        }
        for(int start = i; start < s.length(); start++){
            t = s.substr(i, start - i + 1);
            if(isPalindrome(0, t.size() - 1, t)){
                current.push_back(t);
                solve(current, res, s, start + 1, t);
                current.pop_back();
            }
            
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        solve(current, res, s, 0, "");
        return res;
    }
};