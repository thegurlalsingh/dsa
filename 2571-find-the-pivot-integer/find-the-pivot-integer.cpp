class Solution {
private:
    int solve(vector<int>& nums){
        if(nums.size() == 1){
            return nums[0];
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }
public:
    int pivotInteger(int n) {
        vector<int> arr;
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }
        int pivot = -1;
        for(int i = 0; i < arr.size(); i++){
            vector<int> v1(arr.begin(), arr.begin() + i + 1);
            vector<int> v2(arr.begin() + i, arr.end());
            int sum1 = solve(v1);
            int sum2 = solve(v2);
            if(sum1 == sum2){
                pivot = i + 1;
                break;
            }
        }
        return pivot;
    }
};