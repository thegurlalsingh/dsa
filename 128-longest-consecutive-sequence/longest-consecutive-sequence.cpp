class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        set<int> temp(nums.begin(), nums.end());
        vector<int> num(temp.begin(), temp.end());
        int ans = 1;
        int prev = num[0];
        int c = 1;
        for(int i = 1; i < num.size(); i++){
            if(num[i] - prev == 1){
                prev = num[i]; 
                c++;
                ans = max(c, ans);
            }
            else{
                prev = num[i];
                c = 1;
            }
        }
        return ans;
    }
};