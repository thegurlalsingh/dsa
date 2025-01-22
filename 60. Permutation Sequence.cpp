class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i); 
        }
        
        for (int i = 1; i < k; ++i) {
            next_permutation(nums.begin(), nums.end());
        }
        
        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }
        
        return ans;
    }
};
