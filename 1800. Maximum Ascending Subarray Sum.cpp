class Solution {
private:
    bool check(vector<int> arr){
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] >= arr[i+1]){
                return false;
            }
        }
        return true;
    }
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int count = 0;
                vector<int> newVec(nums.begin() + i, nums.begin() + j + 1);
                if(check(newVec)){
                    count += accumulate(newVec.begin(), newVec.end(), 0);
                }
                maxi = max(count, maxi);
            }
        }
        return maxi;
    }
};