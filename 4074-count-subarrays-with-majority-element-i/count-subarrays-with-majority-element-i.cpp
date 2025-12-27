class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            vector<int>ans;
            int len=0;
            int cnt1=0;
            for(int j=i;j<nums.size();j++){
                len++;
                if(nums[j]==target) cnt1++;
                if(cnt1>len/2) cnt++;
            }
        }
        return cnt;
    }
};