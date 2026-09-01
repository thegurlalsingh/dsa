class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> mp;
        for(int i = 0; i < deadends.size(); i++){
            mp[deadends[i]] = i;
        }
        if(mp.find(target) != mp.end() || mp.find("0000") != mp.end()){
            return -1;
        }
        unordered_set<string> visited;
        int ans = INT_MAX;
        queue<pair<int, string>> q;
        q.push({0, "0000"});
        while(!q.empty()){
            auto [c, s] = q.front(); q.pop();
            if(s == target){
                return c;
            }
            for(int i = 0; i < s.size(); i++){
                for(char ch = '0'; ch <= '9'; ch++){
                    string temp = s;
                    temp[i] = (s[i] == '9') ? '0' : s[i] + 1;
                    if(mp.find(temp) == mp.end() && (visited.find(temp) == visited.end())){
                        q.push({c + 1, temp});
                        visited.insert(temp);
                    }

                    temp = s;
                    temp[i] = (s[i] == '0') ? '9' : s[i] - 1;
                    if(mp.find(temp) == mp.end() && (visited.find(temp) == visited.end())){
                        q.push({c + 1, temp});
                        visited.insert(temp);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};