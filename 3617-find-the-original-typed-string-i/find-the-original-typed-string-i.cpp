class Solution {
private:
    bool check(string& s){
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1]){
                return false;
            }
        }
        return true;
    }
public:
    int possibleStringCount(string word) {
        set<char> s(word.begin(), word.end());
        if(check(word)){
            return 1;
        }
        long long count = 1;
        for(int i = 0; i < word.length() - 1; i++){
            if(word[i] == word[i + 1]){
                int j = i;
                while(word[j] == word[j + 1] && j < word.size()){
                    count++;
                    j++;
                }
                i = j;
            }
        }
        return (int)count;
    }
};