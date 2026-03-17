class Solution {
    long long dp[20][2][2][4][11][200];

    bool s(int x){
        string t = to_string(x);
        if(t.size() == 1) return true;

        bool inc = true, dec = true;
        for(int i = 1; i < t.size(); i++){
            if(t[i] <= t[i-1]) inc = false;
            if(t[i] >= t[i-1]) dec = false;
        }
        return inc || dec;
    }

    long long solve(string &num, int pos, int tight, int started, int dir, int prev, int sum) {
        if (pos == num.size()) {
            if(!started) return 0;

            bool goodNum = (dir != 2);   // not invalid
            bool goodSum = s(sum);

            return (goodNum || goodSum);
        }

        if (dp[pos][tight][started][dir+1][prev][sum] != -1)
            return dp[pos][tight][started][dir+1][prev][sum];

        int limit = (tight ? num[pos] - '0' : 9);
        long long ans = 0;

        for (int digit = 0; digit <= limit; digit++) {
            int newTight = (tight && digit == limit);
            int newStarted = started || (digit != 0);

            if(!newStarted){
                ans += solve(num, pos + 1, newTight, 0, -1, 10, 0);
            }
            else{
                if(prev == 10){
                    ans += solve(num, pos + 1, newTight, 1, -1, digit, digit);
                }
                else{
                    int newDir = dir;

                    if (dir == -1) {
                        if (digit > prev) newDir = 1;
                        else if (digit < prev) newDir = 0;
                        else newDir = 2; 
                    } 
                    else if (dir == 1) {
                        if (digit > prev) newDir = 1;
                        else newDir = 2;
                    } 
                    else if (dir == 0) {
                        if (digit < prev) newDir = 0;
                        else newDir = 2;
                    } 
                    else {
                        newDir = 2; 
                    }

                    ans += solve(num, pos + 1, newTight, 1, newDir, digit, sum + digit);
                }
            }
        }

        return dp[pos][tight][started][dir+1][prev][sum] = ans;
    }

    long long count(long long x){
        if(x < 0) return 0;
        string num = to_string(x);
        memset(dp, -1, sizeof(dp));
        return solve(num, 0, 1, 0, -1, 10, 0);
    }

public:
    long long countFancy(long long l, long long r) {
        return count(r) - count(l - 1);
    }
};