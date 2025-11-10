class Solution {
    bool solve(int i, int j, string &s, string &t){
        if(i >= s.length()){
            return true;
        }
        if(i < s.length() && j >= t.length()){
            return false;
        }
        bool ans = false;
        if(s[i] == t[j]){
            ans = solve(i + 1, j + 1, s, t);

        }
        else{
            ans = solve(i, j + 1, s, t);
        }
        return ans;
    }
public:
    bool isSubsequence(string s, string t) {
        return solve(0, 0, s, t);
    }
};