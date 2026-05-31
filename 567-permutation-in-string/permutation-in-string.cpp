class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz = s1.size();
        sort(s1.begin(), s1.end());
        for(int i = 0; i < s2.size(); i++){
            string t = s2.substr(i, sz);
            sort(t.begin(), t.end());
            if(t == s1){
                return true;
            }
        }
        return false;
    }
};