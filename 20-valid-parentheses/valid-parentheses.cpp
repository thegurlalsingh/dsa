class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '{' || ch == '(' || ch == '[') {
                st.push(ch);
            } 
            else {
                // if (st.empty()) {
                //     return false;
                // }
                bool found = false;
                if (st.empty()) {
                    return false;
                }
                char temp = st.top();
                
                if (ch == ']' && temp == '[') {
                    st.pop();
                    found = true;
                }
                if (ch == '}' && temp == '{') {
                    st.pop();
                    found = true;
                }
                if (ch == ')' && temp == '(') {
                    st.pop();
                    found = true;
                }
                if(!found){
                    st.push(ch);
                }
            }
        }
        return st.empty();
    }
};
