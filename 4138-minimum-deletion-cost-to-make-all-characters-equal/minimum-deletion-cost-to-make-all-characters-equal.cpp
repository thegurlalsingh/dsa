class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> mp; set<char> st;
        for(int i = 0; i < s.length(); i++){
            st.insert(s[i]);
        }
        for (int x : st) {
            for(int i = 0; i < s.length(); i++){
                if(s[i] != x){
                    mp[x] += cost[i];
                }
            }
        }
        long long mini = LLONG_MAX;
        for(auto& p : mp){
            mini = min(mini, p.second);
        }
        return mini == LLONG_MAX ? 0 : mini;
    }
};