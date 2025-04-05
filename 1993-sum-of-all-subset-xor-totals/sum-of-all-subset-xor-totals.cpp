class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for(int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }

    int solve(vector<int>& s){
        int a = 0;
        for(int i = 0; i < s.size(); i++){
            a ^= s[i];
        }
        return a;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        int sum = 0;
        for(int i = 0; i < result.size(); i++){
            sum += solve(result[i]);
        }
        return sum;
    }
};