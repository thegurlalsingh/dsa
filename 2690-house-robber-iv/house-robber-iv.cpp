class Solution {
    int check(int mid, vector<int>& nums, int k){
        int count = 0;
        for(int i = 0; i < nums.size();){
            if(nums[i] <= mid){
                count++;
                i += 2;
            }
            else{
                i++;
            }
        }
        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = 0;
        int high = 1e9;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2; // this mid is max capability of the robber and he can only steal from houses having value less than it
            if(check(mid, nums, k)){
                high = mid - 1; // we are trying to minimize his capability
                ans = min(ans, mid);
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};