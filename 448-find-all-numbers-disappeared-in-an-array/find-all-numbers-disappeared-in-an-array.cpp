class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> arr;
        for(int i = 1; i <= nums.size(); i++){
            if(s.find(i) == s.end()){
                arr.push_back(i);
            }
        }
        return arr;
    }
};