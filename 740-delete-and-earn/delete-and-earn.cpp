 class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_map<int, int> totalSum;
        for(auto num: nums) totalSum[num] += num;

        vector<int> unique;
        for(auto sum: totalSum) unique.push_back(sum.first);

        sort(unique.begin(), unique.end());
        int n = unique.size();
        
        vector<int> dp(n, 0);
        dp[0] = totalSum[unique[0]];
        
        for(int i=1; i<n; i++){
            if(unique[i] == unique[i-1] + 1){
                int take = totalSum[unique[i]] + (i>=2 ? dp[i-2] : 0);
                dp[i] = max(dp[i-1], take);
            }
            else{
                dp[i] = dp[i-1] + totalSum[unique[i]];
            }
        }

        return dp[n-1];
    }
};