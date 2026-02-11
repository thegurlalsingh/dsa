class Solution {
public:
    long long dp[17][2][2];
    long long solve(string &s,int idx,bool tight,bool lz){// lz here is leading zeros
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx][tight][lz]!=-1){
            return dp[idx][tight][lz];
        }
        int lb=0;
        int ub=tight?s[idx]-'0':9;
        long long res=0;
        for(int i=lb;i<=ub;i++){
            if(lz && i==0){
              res+=solve(s,idx+1,0,1);
            }else{
                if(i==0){ // if the digit is zero and it is not leading zero we will not take it 
                    continue;
                }else{
                  res+=solve(s,idx+1,(tight && i==ub),0);
                }
            }
        }
        return dp[idx][tight][lz]=res;
    }
    long long countDistinct(long long n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,1,1)-1;
    }
};