class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n=s.length();
        long long zo=0;
        long long oz=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0' && t[i]=='1'){
                zo++;
            }else if(s[i]=='1' && t[i]=='0') {
                oz++;
            }
        }
        long long u1=min(zo,oz);
        long long c1=u1*min(swapCost,flipCost*2);
        zo-=u1;
        oz-=u1;
        long long rem=abs(zo-oz);
        long long c2=min(rem*flipCost,(rem/2)*(crossCost+swapCost) + (rem%2)*flipCost);
        return c1+c2;
    }
};