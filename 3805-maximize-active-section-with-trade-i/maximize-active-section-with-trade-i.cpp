class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (int i = 0; i < s.size(); i++) 
            if (s[i] == '1') 
                ones++;
        
        string t = "1" + s + "1";
        vector<int> v;
        int cnt = 1;
        
        for (int i = 1; i < t.size(); i++) {
            if (t[i] == t[i - 1]) 
                cnt++;
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        
        int mx = 0;
        for (int i = 2; i < (int)v.size() - 2; i += 2) 
            mx = max(mx, v[i - 1] + v[i + 1]);
        
        return ones + mx;
    }
};

