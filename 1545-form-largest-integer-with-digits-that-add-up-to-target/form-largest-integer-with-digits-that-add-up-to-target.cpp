class Solution {
   
    vector<string>dp;
    string find_answer(vector<int>&cost, int target)
    {
       
        if(target == 0)
        return "";

        if(dp[target] != "#")
        return dp[target];

        string curr = "", answer = "0";
        for(int i=0; i<cost.size(); i++)
        {
            if(target - cost[i] < 0)
            continue;

            curr = find_answer(cost, target - cost[i]);

            if(curr == "0")
            continue;

            curr = to_string(i+1) + curr;

            if(answer.size() <= curr.size())
            {
                answer = curr;
            }
        }

        return dp[target] = answer;
    }
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        dp.clear();
        dp.resize(5002, "#");
       return find_answer(cost, target);
        
    }
};