class Solution {
    pair<bool, int> helper(string& temp_source, string& temp_target, string& rule) {
        bool ok = true;
        int count = 0;
        for (int i = 0; i < temp_source.size(); i++) {
            if (rule[i] != '*' && (temp_source[i] != rule[i])) {
                ok = false;
                break;
            } else if (rule[i] == '*') {
                count++;
            }
        }

        return {ok, count};
    }

    int solve(int i, string& source, string& target, vector<vector<string>>& rules, vector<int>& costs, vector<int>& dp) {
        if (i >= source.size()) {
            return 0;
        }
        if(dp[i] != -2){
            return dp[i];
        }
        int ans = INT_MAX;
        if (source[i] == target[i]) {
            ans = min(ans, solve(i + 1, source, target, rules, costs, dp));
        }
        for (int j = 0; j < rules.size(); j++) {
            int len = rules[j][0].size();
            if (i + len <= source.size()) {
                string temp_source = source.substr(i, len);
                string temp_target = target.substr(i, len);
                pair<bool, int> k = helper(temp_source, temp_target, rules[j][0]);
                if (k.first && (temp_target == rules[j][1])) {
                    int t = solve(i + len, source, target, rules, costs, dp);
                    if (t != INT_MAX) {
                        ans = min(ans, costs[j] + k.second + t);
                    }
                }
            }
        }
        

        return dp[i] = ans;
    }

public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        vector<int> dp(source.size() + 1, -2);
        int ans = solve(0, source, target, rules, costs, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};