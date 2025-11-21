class Solution {
public:
    int K;
    int dp[20001][4];

    int helper(vector<int> &ans, int i, int limit){
        if(limit == 0) return 0;
        if(i >= ans.size()) return INT_MIN;

        if(dp[i][limit] != -1) return dp[i][limit];

        int include = ans[i] + helper(ans, i + K, limit - 1);
        int exclude = helper(ans, i + 1, limit);

        return dp[i][limit] = max(include, exclude);
    }

    void Solve(vector<int>& ans, int i, int limit, vector<int> &result){
        if(limit == 0 || i >= ans.size()) return;

        int include = ans[i] + helper(ans, i + K, limit - 1);
        int exclude = helper(ans, i + 1, limit);

        // LEXICOGRAPHICALLY SMALLEST
        if(include >= exclude){           // <= THIS LINE GIVES LEXICOGRAPHIC SMALLEST
            result.push_back(i);
            Solve(ans, i + K, limit - 1, result);
        } 
        else {
            Solve(ans, i + 1, limit, result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        K = k;

        vector<int> ans;
        int sum = 0;

        // Build subarray sums
        for(int i = 0, j = 0; j < n; j++){
            sum += nums[j];
            if(j - i + 1 == k){
                ans.push_back(sum);
                sum -= nums[i++];
            }
        }

        memset(dp, -1, sizeof(dp));

        vector<int> result;
        Solve(ans, 0, 3, result);

        return result;
    }
};