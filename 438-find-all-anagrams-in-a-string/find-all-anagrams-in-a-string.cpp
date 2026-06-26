class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> f(26, 0);
        vector<int> count(26, 0);
        vector<int> ans;
        int len = 0;
        sort(p.begin(), p.end());
        for(int i = 0; i < p.size(); i++){
            count[p[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            f[s[i] - 'a']++;
            len++;
            if(len == p.size()){
                if(count == f){
                    ans.push_back(i - p.size() + 1);
                }
                len--;
                f[s[i - p.size() + 1] - 'a']--;
            }
        }
        return ans;
    }
};