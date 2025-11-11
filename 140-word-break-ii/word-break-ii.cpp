class Solution {
    void helper(string& str, vector<string>& current){
        for(int i = 0; i < current.size(); i++){
            str += current[i];
            if(i != current.size() - 1){
                str += " ";
            }
        }
    }
    void solve(int i, string s, unordered_set<string>& words, vector<string>& result, vector<string>& current){
        if(i >= s.length()){
            string temp = "";
            helper(temp, current);
            result.push_back(temp);
            return ;
        }

        for(int j = i; j < s.length(); j++){
            if(words.find(s.substr(i, j - i + 1)) != words.end()){
                current.push_back(s.substr(i, j - i + 1));
                solve(j + 1, s, words, result, current);
                current.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<string> result;
        vector<string> current;
        solve(0, s, words, result, current);
        return result;
    }
};