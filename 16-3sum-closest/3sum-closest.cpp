class Solution {
private:
    int threeSum(vector<int>& nums, int target) {
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2]; 
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }
                else if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return result;
    }

public:
    int threeSumClosest(vector<int>& nums, int target) {
        return threeSum(nums, target);
    }
};
