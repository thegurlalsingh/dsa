class Solution {
    long long dp[20][2][11]; // idx, tight, prev

    string num;
    int k;

    long long solve(int pos, int tight, int prev) {
        if(pos == num.size()){
            if(prev != 10){
                return 1;
            }
            return 0;
        }

        if(dp[pos][tight][prev] != -1)
            return dp[pos][tight][prev];

        long long ans = 0;

        int limit = tight ? num[pos]-'0' : 9;

        for(int digit = 0; digit <= limit; digit++){

            int newTight = tight && (digit == limit);
            if(prev == 10){
                if(digit == 0){
                    ans += solve(pos + 1, newTight, 10); // if current is 0 and prev was 10, continue ignoring zero
                }
                else{
                    ans += solve(pos + 1, newTight, digit); // now its the first number 
                }
            }
            else{
                if(abs(digit - prev) <= k){
                    ans += solve(pos + 1, newTight, digit);
                }
            }
        }

        return dp[pos][tight][prev] = ans;
    }

    long long f(long long x){

        if(x < 0) return 0;

        num = to_string(x);

        memset(dp,-1,sizeof(dp));

        return solve(0,1,10);
    }

public:
    long long goodIntegers(long long l, long long r, int k) {
        this->k = k;
        return f(r)-f(l-1);
    }
};