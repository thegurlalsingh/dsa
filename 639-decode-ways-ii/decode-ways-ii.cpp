class Solution
{
    public:
        int MOD = 1e9 + 7;
    int decodings(int ind, string &s, vector<int> &dp)
    {
        if (ind == s.size())
           	//If we have reached the string end then we have only one choice
           	//to take the remaining char
            return 1;
        if (s[ind] == '0')
           	//invalid choice
            return 0;
        if (dp[ind] != -1)
           	//Already solved
            return dp[ind];

        long long oneCharChoice = decodings(ind + 1, s, dp);
       	//Choice of choosing 1 char
        if (s[ind] == '*')
            oneCharChoice = (oneCharChoice *9) % MOD;
       	//If the 1 char is '*' then there are 9 ways of replacing that with char

        long long twoCharChoice1 = 0;
       	//Double digits choice in whic the 1st char is 1
        long long twoCharChoice2 = 0;
       	//Double digits choice in whic the 1st char is 2

        if (ind + 1 < s.size())
        {
            if (s[ind] == '1' || s[ind] == '*')
            {
                twoCharChoice1 = decodings(ind + 2, s, dp);
                if (s[ind + 1] == '*')
                {
                    twoCharChoice1 = (twoCharChoice1 *9) % MOD;
                   	//9 ways of replacing '*' 
                }
            }
            if (s[ind] == '2' || s[ind] == '*')
            {
                if (s[ind + 1] == '*')
                {
                    twoCharChoice2 = decodings(ind + 2, s, dp);
                    twoCharChoice2 = (6 *twoCharChoice2) % MOD;
                   	//6 ways of replacing '*' 
                }
                    else if (s[ind + 1] - '0' <= 6)
                    {
                       	//Normal digit other than '*'
                        twoCharChoice2 = decodings(ind + 2, s, dp);
                    }
                }
            }
            return dp[ind] = ((oneCharChoice + twoCharChoice1) % MOD + twoCharChoice2) % MOD;
           	//Storing of all choices
        }
        int numDecodings(string s)
        {
            int n = s.size();
            vector<int> dp(n + 1, -1);
            return decodings(0, s, dp);
        }
    };