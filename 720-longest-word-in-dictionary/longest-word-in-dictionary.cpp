class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s;
        for(int i = 0; i < words.size(); i++){
            s.insert(words[i]);
        }

        string ans = "";
        s.insert("");
        for(int i = 0; i < words.size(); i++){
            string temp = words[i].substr(0, words[i].size() - 1);
            bool found = true;
            for(int j = 1; j <= temp.size(); j++){
                string t = temp.substr(0, j);
                if(s.find(t) == s.end()){
                    found = false;
                    break;
                }
            }
            if(found){
                if(ans == "" || words[i].size() > ans.size() || (words[i].size() == ans.size() && words[i] < ans)){
                    ans = words[i];
                }
            }
        }

        return ans;
    }
};