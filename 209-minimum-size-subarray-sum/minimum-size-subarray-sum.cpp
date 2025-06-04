class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int minLen = INT_MAX;

        while (j < n) {
            sum += nums[j];

            while (sum >= target) {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i]; 
                i++;
            }

            j++;
        }

        if(minLen == INT_MAX) {
            return 0;
        }
        else{
            return minLen;
        }
    }
};
