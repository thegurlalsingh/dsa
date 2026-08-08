class Solution {
    int check(string& u, string& temp_u){
        int ans = 0;
        for(int i = 0; i < u.size(); i++){
            if(u[i] != temp_u[i]){
                if(u[i] == '*'){
                    ans++;
                }
                else{
                    ans = -1; break;
                }
            }
        }
        return ans;
    }
    int solve(int i, string& source, string& target, vector<vector<string>>& rules, vector<int>& costs, vector<int>& dp){
        if(i >= source.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int cost = INT_MAX;

        if(source[i] == target[i]){
            cost = min(cost, solve(i + 1, source, target, rules, costs, dp));
        }

        for(int j = 0; j < rules.size(); j++){
            string u = rules[j][0]; string v = rules[j][1];
            string temp_u = source.substr(i, u.size());
            string temp_v = target.substr(i, v.size());
            int p = check(u, temp_u);
            if(p != -1 && (v == temp_v)){
            int t = solve(i + temp_u.size(), source, target, rules, costs, dp);
                if(t != INT_MAX){
                    int temp_cost = costs[j] + p + t;
                    cost = min(cost, temp_cost);
                }     
            }
        }
        return dp[i] = cost;
    }
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        vector<int> dp(source.size(), -1);
        int ans = solve(0, source, target, rules, costs, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};