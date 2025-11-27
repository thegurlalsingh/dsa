class Solution {
public:
    int n;
    int dp[1001][1001];
    bool checkPredecessor(string &prev,string &curr){
        int M=prev.length(),N=curr.length();
        
        if(M>=N || N-M!=1) return false;
        
        int i=0,j=0;

        while(i<M && j<N){
            if(prev[i]==curr[j]){
                i++;
            }
            j++;
        }
        return i==M;
    }
    int solve(vector<string>&words,int prev,int i){
        if(i>=n) return 0;

        if(prev!=-1 && dp[prev][i]!=-1) return dp[prev][i];

        int take=0;
        if(prev==-1 || checkPredecessor(words[prev],words[i])){
            take=1+solve(words,i,i+1);
        }

        int skip=solve(words,prev,i+1);
        
        if(prev!=-1){
            dp[prev][i]=max(take,skip);
        }

        return max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();

        auto lambda=[](string &a,string &b){
            return a.length()<b.length();
        };

        sort(begin(words),end(words),lambda);

        memset(dp,-1,sizeof(dp));

        return solve(words,-1,0);
    }
};