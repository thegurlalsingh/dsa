class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(int i = 0; i < strs.size(); i++){
            if(strs[i][0] != res[0]){
                return "";
            }
            string f = "";
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] != res[j]){
                    break;
                }
                else{
                    f += strs[i][j];
                }
            }
            res = f;
        }
        return res;
    }
};