class Solution {
    bool helper(int l, int r, vector<int>& nums) {
        int x = nums[r];
        unordered_map<int, int> mp;

        for (int k = l; k < r; k++) {
            mp[nums[k]]++;
        }

        // Case 1: a + b = x
        for (int k = l; k < r; k++) {
            int a = nums[k];
            int b = x - a;

            if (mp.find(b) != mp.end()) {
                // make sure we have two distinct indices
                if (a != b || mp[a] >= 2) {
                    return true;
                }
            }
        }

        // Case 2: x + a = b
        for (int k = l; k < r; k++) {
            int b = x + nums[k];
            if (mp.find(b) != mp.end()) {
                return true;
            }
        }

        return false;
    }

public:
    int maxSubarray(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }
        int maxLen = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while (j < n) {
            if (j - i + 1 < 3) {
                j++;
                continue;
            }
            while (helper(i, j, nums)) { // if helper returned any tuple of nums[i] + nums[j] == nums[k] then this will start shrinking
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};