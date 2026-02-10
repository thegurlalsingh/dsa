class Solution {
    int reverseNum(int x){
        int r = 0;
        while(x > 0){
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dist = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int f = nums[i];
            int r = reverseNum(nums[i]);

            if(mp.count(f)){
                dist = min(dist, abs(i - mp[f]));
            }
            mp[r] = i;
        }
        return dist == INT_MAX ? -1 : dist;
    }
};
