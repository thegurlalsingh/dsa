class Solution {
private:
    bool isPrefix(string &check, string &s) {
        int n = check.length();
        string s1 = s.substr(0, n);
        return s1 == check;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            if(isPrefix(pref, words[i])){
                count++;
            }
        }
        return count;
    }
};
