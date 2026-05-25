class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int j = n - 1;
            while(i < j){
            int sum = temp[i].first + temp[j].first;
            if(sum == target){
                return {temp[i].second, temp[j].second};
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        }
        return {};
    }
};