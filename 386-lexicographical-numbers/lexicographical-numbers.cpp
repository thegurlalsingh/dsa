class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> res;
        for(int i = 0; i < n + 1; i++){
            res.push_back(to_string(i));
        }
        sort(res.begin(), res.end());
        vector<int> s;
        for(int i = 0; i < res.size(); i++){
            s.push_back(stoi(res[i]));
        }
        s.erase(s.begin());
        return s;
    }
};