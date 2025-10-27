class Solution {
    vector<vector<int>> memo;
    bool solve(int i, vector<int>& nums, int sum1, int sum2, int half){
        if (sum1 > half || sum2 > half){  
            return false;
        }
        if(i == nums.size()){
            if(sum1 == half && sum2 == half){
                return true;
            }
            return false;
        }
        if(memo[i][sum1] != -1){
            return memo[i][sum1];
        }
        int p1 = solve(i + 1, nums, sum1 + nums[i], sum2, half);
        int p2 = solve(i + 1, nums, sum1, sum2 + nums[i], half);
        return memo[i][sum1] = p1 || p2;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        memo.resize(nums.size(), vector<int>(sum/2 + 1, -1));
        int half = sum/2;
        return solve(0, nums, 0, 0, half);
    }
};