class Solution {
public:
    string _max(string a , string b){
        if(a.length() != b.length()){
            return (a.length() < b.length()) ? b : a;
        }else{
            return max(a,b);
        }
    }
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>> dp(10 , vector<string>(target+1 , ""));
        //base case
        for(int t=1;t<=target;t++)dp[0][t] = "0";
        //dp
        for(int i=0;i<=8;i++){
            for(int t=1;t<=target;t++){
                if(t >= cost[i]){
                    string take = dp[i+1][t-cost[i]];
                    if(take != "0")take = to_string(i+1) + take;
                    string not_take = dp[i][t];

                    dp[i+1][t] = _max(take , not_take);
                }else{
                    dp[i+1][t] = dp[i][t];
                }
            }
        }

        string ans = dp[9][target];
        return (ans.empty()) ? "0" : ans;
    }
};