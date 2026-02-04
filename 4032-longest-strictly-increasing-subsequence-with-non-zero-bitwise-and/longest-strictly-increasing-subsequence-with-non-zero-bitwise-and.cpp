class Solution {
public:
    int findLIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        vector<int> temp;
        temp.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();

                temp[idx] = nums[i];
            }
        }

        return temp.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < 32; i++) {
            vector<int> newArr;

            for (int k = 0; k < n; k++) {
                if ((nums[k] & (1 << i)) != 0) {
                    newArr.push_back(nums[k]);
                }
            }

            ans = max(ans, findLIS(newArr));
        }

        return ans;
    }
};