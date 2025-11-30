class Solution {
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[reverseNum(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
