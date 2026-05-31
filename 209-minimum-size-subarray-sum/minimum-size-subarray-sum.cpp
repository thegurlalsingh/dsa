class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(), nums.end(), 0) < target){
            return 0;
        }
        map<int, int> mp;
        mp[0] = -1;
        int prefix = 0;
        int dis = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];  
            int diff = prefix - target;
            auto it = mp.upper_bound(diff);
            if(it != mp.begin()){
                --it;
                int t = it->second;
                // if(t == -1){
                //     t = 0;
                // }
                dis = min(dis, i - t);
            }
            mp[prefix] = i;
        }
        return dis;
    }
};