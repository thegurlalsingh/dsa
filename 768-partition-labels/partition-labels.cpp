class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>> mp;

        // store first & last occurrence
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]].second = i;
            }
        }

        vector<int> ans;

        for(int i = 0; i < s.size(); i++){
            int start = i;
            int end = mp[s[i]].second;

            for(int j = start; j <= end; j++){
                end = max(end, mp[s[j]].second);
            }

            ans.push_back(end - start + 1);
            i = end;
        }

        return ans;
    }
};