class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int t = st.top(); st.pop();
                if(t == 0){
                    t++;
                }
                else{
                    t *= 2;
                }
                int parent = st.top();
                st.pop();
                st.push(parent + t);
            }
        }
        return st.top();
    }
};