class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end()){
            return 0;
        }

        unordered_set<string> visited;

        // int moves = INT_MAX;

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            if(t.first == endWord){
                return t.second + 1;
            }

            for(char w = 'a'; w <= 'z'; w++){
                for(int i = 0; i < t.first.size(); i++){
                    string temp = t.first;
                    temp[i] = w;
                    if(st.count(temp) && (visited.find(temp) == visited.end())){
                        q.push({temp, t.second + 1});
                        visited.insert(temp);
                    }
                }
            }
        }

        return 0;
    }
};