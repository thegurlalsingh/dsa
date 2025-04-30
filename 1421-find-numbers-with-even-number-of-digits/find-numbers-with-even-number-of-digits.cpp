class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<int> size;
        for(int i = 0; i < nums.size(); i++){
            string s = to_string(nums[i]);
            size.push_back(s.length());
        }
        int count = 0;
        for(int i = 0; i < size.size(); i++){
            if(size[i] % 2 == 0){
                count++;
            }
        }
        return count;
    }
};