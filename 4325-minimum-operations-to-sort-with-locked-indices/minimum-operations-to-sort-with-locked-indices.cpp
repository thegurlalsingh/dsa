class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int operations = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (locked[j] == 1 && locked[j + 1] == 0) {
                        if (k > 0) {
                            locked[j] = 0;
                            operations++;
                            k--;
                        } else {
                            return -1;
                        }
                    }
                    if (locked[j + 1] == 1 && locked[j] == 0) {
                        if (k > 0) {
                            locked[j + 1] = 0;
                            operations++;
                            k--;
                        } else {
                            return -1;
                        }
                    }
                    if (locked[j] == 1 && locked[j + 1] == 1) {
                        if (k >= 2) {
                            locked[j] = 0;
                            locked[j + 1] = 0;
                            operations += 2;
                            k -= 2;
                        } else {
                            return -1;
                        }
                    }
                    operations++;
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return operations;
    }
};
