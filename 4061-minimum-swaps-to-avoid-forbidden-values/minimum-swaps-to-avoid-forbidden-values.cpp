class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();

        int count = 0;
        unordered_map<int, int> same;

        int maxCount = 0;
        int maxCountNum = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == forbidden[i]) {
                same[nums[i]]++;
                if(maxCount < same[nums[i]]) {
                    maxCount = same[nums[i]];
                    maxCountNum = nums[i];
                }
                count++;
            }
        }

        if(count == 0) return 0;

        if(maxCount <= count - maxCount) return (count + 1) / 2;

        int diff = count - maxCount;
        int rem = 2 * maxCount - count;
        int ans = diff;

        for(int i = 0; i < n; i++) {
            if(nums[i] == forbidden[i]) continue;
            if(nums[i] != maxCountNum && forbidden[i] != maxCountNum) rem--;
        }
        
        if(rem <= 0) return ans + (2 * maxCount - count);
        else return -1;
        
    }
};