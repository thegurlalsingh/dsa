class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        vector<int> opening; 
        vector<int> closing;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                opening.push_back(i);
            }
            else if(s[i] == ')'){
                if(!opening.empty()){
                    opening.pop_back();
                }
                else{
                    closing.push_back(i);
                }
            }
        }

        vector<int> visited(s.size(), 0);
        for(int i = 0; i < opening.size(); i++){
            visited[opening[i]] = 1;
        }
        for(int i = 0; i < closing.size(); i++){
            visited[closing[i]] = 1;
        }
        for(int i = 0; i < s.size(); i++){
            if(visited[i] != 1){
                ans += s[i];
            }
        }
        return ans;
    }
};