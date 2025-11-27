class Solution {
    unordered_map<int, bool> memo;

    bool solve(string &word, unordered_set<string> &s, int k, int index, int count) {
        if (index == word.size())
            return count >= k;

        if (memo.count(index)) 
            return memo[index];

        for (int end = index; end < word.size(); end++) {
            string sub = word.substr(index, end - index + 1);

            if (s.count(sub)) {
                if (solve(word, s, k, end + 1, count + 1))
                    return memo[index] = true;
            }
        }

        return memo[index] = false;
    }

    bool helper(string str, unordered_set<string>& s){
        memo.clear();       // ❗ clear memo for each word
        s.erase(str);       // ❗ avoid counting the word itself
        int k = 2;
        bool ans = solve(str, s, k, 0, 0);
        s.insert(str);      // restore
        return ans;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> result;

        for(int i = 0; i < words.size(); i++){
            if(helper(words[i], s)){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
