class Solution {
private:
    string check(string s){
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string r = "";
        while(!st.empty()){
            r += st.top();
            st.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
public:
    bool backspaceCompare(string s, string t) {
        return check(s) == check(t);
    }
};