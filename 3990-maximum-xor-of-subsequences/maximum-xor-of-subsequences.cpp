class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> basis(32, 0);

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];

            for (int j = 31; j >= 0; j--) {

                if ((val & (1 << j)) == 0)
                    continue;

                if (basis[j] == 0) {
                    basis[j] = val;
                    break; 
                }
                else {
                    val ^= basis[j];
                }
            }
        }

        int ans = 0;

        for (int bit = 31; bit >= 0; bit--) {
            if ((ans ^ basis[bit]) > ans) {
                ans ^= basis[bit];
            }
        }

        return ans;
    }
};