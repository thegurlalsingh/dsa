class Solution {
    int solve(vector<int>& nums){
        int operations = 0;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int offset = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int start = i;
            int end = (i - offset + n) % n;
            if(nums[start] == mini && nums[end] == maxi){
                for (int j = 0; j < n; j++) {
                    int next = (j + 1) % n;
                    if (nums[next] != (nums[j] + 1) % n){
                        return INT_MAX;
                    }
                }
                return operations;
            }
            else if(nums[start] == maxi && nums[end] == mini){
                for (int j = 0; j < n; j++) {
                    int next = (j + 1) % n;
                    if (nums[next] != (nums[j] - 1 + n) % n){
                        return INT_MAX;
                    }
                }
                return operations + 1;
            }
            else{
                operations++;
            }
        }
        return INT_MAX;
    }
public:
    int minOperations(vector<int>& nums) {
        vector<int> rev = nums;
        reverse(nums.begin(), nums.end());
        int way1 = solve(nums);
        int way2 = solve(rev);
        if(way1 != INT_MAX){
            way1++;
        }
        int ans = min(way1, way2);
        return ans == INT_MAX ? -1 : ans;
    }
};