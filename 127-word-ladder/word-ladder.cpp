class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord){
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {

                    string temp = word;
                    temp[i] = ch;

                    if (st.count(temp)) {
                        st.erase(temp); 
                        q.push({temp, steps + 1});
                    }
                }
            }
        }

        return 0;
    }
};