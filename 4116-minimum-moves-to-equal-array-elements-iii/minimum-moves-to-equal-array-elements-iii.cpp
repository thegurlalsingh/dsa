class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int elem = *max_element(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += abs(nums[i] - elem);
        }
        return count;
    }
};