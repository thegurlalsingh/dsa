class Solution {
private:
    bool check(string y, char x){
        for(int i = 0; i < y.size(); i++){
            if(x == y[i]){
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i = 0; i < words.size(); i++){
            if(check(words[i], x)){
                res.push_back(i);
            }
        }
        return res;
    }
};