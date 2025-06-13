class Solution {
private:
    bool is_possible(int diff, vector<int>& v, int p){
        for(int i=0;i<v.size()-1;){
            if(v[i+1]-v[i] <= diff){
                p--;
                if(p==0){return true;}
                i++;
            }

            i++;
        }

        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0){return 0;}
        
        int n = nums.size();
        sort(begin(nums), end(nums));

        int l = 0, r = nums[n-1] - nums[0];
        int mn_diff = r;

        while(l<=r){
            int mid = (l+r)>>1;

            if(is_possible(mid, nums, p)){
                mn_diff = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return mn_diff;
    }
};