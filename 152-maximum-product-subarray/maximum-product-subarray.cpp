class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxi(nums.size(), 0);
        vector<int> mini(nums.size(), 0);
        maxi[0] = nums[0];
        mini[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxi[i] = max({nums[i], nums[i] * maxi[i - 1], nums[i] * mini[i - 1]});
            mini[i] = min({nums[i], nums[i] * maxi[i - 1], nums[i] * mini[i - 1]});
        }
        int m_maxi = *max_element(maxi.begin(), maxi.end());
        int m_mini = *max_element(mini.begin(), mini.end());
        return max(m_maxi, m_mini);
    }
};