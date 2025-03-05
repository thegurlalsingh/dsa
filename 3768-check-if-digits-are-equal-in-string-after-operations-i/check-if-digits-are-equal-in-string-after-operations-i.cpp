class Solution {
private:
    void solve(string& res, string& s){
        res = "";
        for(int i = 0; i < s.length() - 1; i++){
            res += to_string(((s[i] - '0') + (s[i + 1] - '0')) % 10);
        }
    }
public:
    bool hasSameDigits(string s) {
        string res = "";
        string temp = s;
        while(true){
            if(res.size() == 2){
                if(res[0] == res[1]){
                    return true;
                }
                return false;
            }
            solve(res, temp);
            temp = res;
        }
        return false;
    }
};