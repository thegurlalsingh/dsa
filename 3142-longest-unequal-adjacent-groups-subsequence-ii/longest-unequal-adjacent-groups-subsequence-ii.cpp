class Solution {
private:
    bool checkhammingDistanceOne(string &s1, string &s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        int diff = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
            }
            if(diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

    int LIS(int curr, int prev, vector<string>& words, vector<int>& groups, vector<vector<int>>& dp) {
        if (curr == words.size()) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        int notTake = LIS(curr + 1, prev, words, groups, dp);

        int take = 0;
        if (prev == -1 || (groups[curr] != groups[prev] && checkhammingDistanceOne(words[prev], words[curr]))) {
            take = 1 + LIS(curr + 1, curr, words, groups, dp);
        }

        return dp[curr][prev + 1] = max(take, notTake);
    }

    void reconstruct(int curr, int prev, vector<string>& words, vector<int>& groups, vector<vector<int>>& dp, vector<string>& result) {
        if (curr == words.size()) {
            return;
        }

        int notTake = LIS(curr + 1, prev, words, groups, dp);

        if (prev == -1 || (groups[curr] != groups[prev] && checkhammingDistanceOne(words[prev], words[curr]))) {
            int take = 1 + LIS(curr + 1, curr, words, groups, dp);
            if (take >= notTake) {
                result.push_back(words[curr]);
                reconstruct(curr + 1, curr, words, groups, dp, result);
                return;
            }
        }

        reconstruct(curr + 1, prev, words, groups, dp, result);
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<string> result;

        LIS(0, -1, words, groups, dp);
        reconstruct(0, -1, words, groups, dp, result);
        return result;
    }
};