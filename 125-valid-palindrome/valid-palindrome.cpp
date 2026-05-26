class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                t += tolower(s[i]);
            }
        }
        if(t[0] == '\n'){
            return true;
        }
        int i = 0; int j = t.size() - 1;
        while(i < j){
            if(t[i] != t[j]){
                return false;
            }
            else{
                i++; j--;
            }
        }
        return true;
    }
};