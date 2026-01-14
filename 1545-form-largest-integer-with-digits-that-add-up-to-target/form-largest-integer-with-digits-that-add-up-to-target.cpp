class Solution
{
public:
    string solve(int tgt, vector<int> &c, vector<string> &dp)
    {
        if (tgt == 0)
        {
            return "";
        }
        if (dp[tgt] != "#")
        {
            return dp[tgt];
        }
        string ans = "0";
        for (int i = 1; i <= 9; i++)
        {
            if (tgt >= c[i-1])
            {
                string curr = solve(tgt - c[i - 1], c, dp);
                if(curr=="0")continue;
                curr = to_string(i)+curr;
                if(ans.length()>curr.length())continue;
                if((ans=="0")||(curr.length()>ans.length())||(curr.length()==ans.length()&&curr.compare(ans)>0)){
                    ans =curr;
                }
            }
        }
        return dp[tgt] = ans;
    }
    string largestNumber(vector<int> &cost, int target)
    {
        vector<string> dp(target + 1, "#");
        return solve(target, cost, dp);
    }
};