class Solution {
public:
    vector<int>pre;
    vector<vector<vector<int>>>dp;
    vector<int> f(vector<int>&nums,int k,int i,int count){
        if(count==0) return {};
        if((i+k-1)>=nums.size()){
            return {};
        }
        if(dp[i][count].size()!=0) return dp[i][count];
        vector<int>nt= f(nums,k,i+1,count);
        vector<int>t;
        t.push_back(i);
        vector<int>t1 = f(nums,k,i+k,count-1);
        t.insert(t.end(),t1.begin(),t1.end());
        int nsum = 0;
        int sum = 0;
        for(int j=0;j<nt.size();j++){
            int y = nt[j]+k;
            int x = nt[j];
            nsum += (pre[y]-pre[x]);
        }
        for(int j=0;j<t.size();j++){
            int y = t[j]+k;
            int x = t[j];
            sum += (pre[y]-pre[x]);
        }
        if(nsum>sum) return dp[i][count] = nt;
        else return dp[i][count] = t;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        pre.resize(n+1);
        dp.resize(20005,vector<vector<int>>(4));
        pre[0] = 0;
        for(int i=0;i<n;i++){
            pre[i+1] = nums[i] + pre[i];
        }
        return f(nums,k,0,3);
    }
};