class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        for(int i = 0; i < wordList.size(); i++){
            mp[wordList[i]] = i;
        }
        if(mp.find(endWord) == mp.end()){
            return 0;
        }
        vector<int> visited(wordList.size(), 0);
        int ans = INT_MAX;
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while(!q.empty()){
            auto [c, s] = q.front(); q.pop();
            if(mp.find(s) != mp.end()){
                int index = mp[s];
                if(visited[index]){
                    continue;
                }
                visited[index] = 1;
            }
            if(s == endWord){
                ans = min(ans, c);
                continue;
            }
            for(int i = 0; i < s.size(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    string temp = s;
                    temp[i] = ch;
                    if(mp.find(temp) != mp.end()){
                        q.push({c + 1, temp});
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};