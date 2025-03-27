class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = n-1;
        int operationCount = 0;

        sort(nums.begin(), nums.end());

        while(i < j){
            int sum = nums[i]+nums[j];
            if(sum == k){
                operationCount++;
                i++;
                j--;
            }
            else if(sum > k){
                j--;
            }

            else{
                i++;
            }
        }
        return operationCount;
    }
};