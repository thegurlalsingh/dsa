class Solution {
    bool check(char c, unordered_map<char, vector<int>>& mp, int idx){
        for(int i = 0; i < mp[c].size(); i++){
            if(mp[c][i] > idx){
                return true;
            }
        }
        return false;
    }
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }
        unordered_set<char> used;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if (used.count(s[i])) {
                continue;
            }
            while(!st.empty() && s[i] < st.top() && check(st.top(), mp, i)){
                used.erase(st.top());
                st.pop();
            }
            used.insert(s[i]);
            st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};