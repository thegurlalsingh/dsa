class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        do {
            vector<int> temp;
            for (int num : nums) {
                temp.push_back(num);
            }
            arr.push_back(temp);
        }
        while (next_permutation(nums.begin(), nums.end()));
        return arr;
    }
};