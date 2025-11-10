class Solution {
    bool isPalindrome(string& s){
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, string &s, vector<string>& current, vector<vector<string>>& result){
        if(i >= s.length()){
            result.push_back(current);
            return ;
        }
        for(int j = i; j < s.length(); j++){
            string sub = s.substr(i, j - i + 1);
            if(isPalindrome(sub)){
                current.push_back(sub);
                solve(j + 1, s, current, result);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        solve(0, s, current, result);
        return result;
    }
};