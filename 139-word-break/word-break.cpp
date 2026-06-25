class Solution {
    bool solve(int i, string& s, unordered_set<string>& w, vector<int>& dp){
        if(i >= s.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        bool take = false;
        for(int end = i; end < s.size(); end++){
            string sub = s.substr(i, end - i + 1);
            if(w.find(sub) != w.end()){
                if(solve(end + 1, s, w, dp)){
                    take = true;
                }
            }
        }
        return dp[i] = take;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> w(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, w, dp);
    }
};