
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int i = 0;
        int j = -1;
        int mod = -1;
        int ans = 1;
        int len = 0;

        while (j < (int)nums.size() - 1) {
            j++;

            if (mod == -1 || (nums[j] % k) == mod) {
                int l = j - i + 1;
                mod = nums[j] % k;

                if (((l - 1LL) * mod) % k == 0) {
                    len = max(len, l);
                }
            }
            else {
                i = j;
                mod = nums[j] % k;
                len = 1;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
