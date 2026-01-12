class Solution {
public:
    const int M = 1e9+7;
    int dp[1005][1005][2];
    int f(int n,int k,int i,bool flag){
        if(i==n){
            if(k==0 and flag==false) return 1;
            else return 0;
        }
        if(dp[i][k][flag]!=-1) return dp[i][k][flag];
        int ans = 0;
        if(flag==false){
            ans = (ans + f(n,k,i+1,flag))%M;
            if(k>0) ans = (ans + f(n,k-1,i+1,true))%M;
        }
        else{
            ans = (ans + f(n,k,i+1,flag))%M;
            ans = (ans + f(n,k,i,false))%M;
        }
        return dp[i][k][flag] = ans;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k,0,false);
    }
};