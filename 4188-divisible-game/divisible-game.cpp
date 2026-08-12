class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int ans = INT_MIN;
        int k_ = INT_MAX; 
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<vector<int>> indices(maxVal + 1);
        for(int i = 0; i < nums.size(); i++){
            indices[nums[i]].push_back(i);
        }

        unordered_map<int, unordered_set<int>> mp;
        for(int i = 2; i <= maxVal; i++){
            for(int j = i; j <= maxVal; j += i){
                for(int index : indices[j]){
                    mp[i].insert(index);
                }
            }
        }
        
        if (mp.empty()) {
                long long ans = -(*min_element(nums.begin(), nums.end()));
                return ((long long)ans * 2 % 1000000007 + 1000000007) % 1000000007;
            }
        for (auto k : mp) {
            vector<int> temp = nums;
            unordered_set<int> val = k.second;
            for(int j = 0; j < temp.size(); j++){
                if(val.find(j) == val.end()){
                    temp[j] = -temp[j];
                }
            }
            
            int cur = 0;
            int best = INT_MIN;

            for (int x : temp) {
                cur = max(x, cur + x);
                best = max(best, cur);
            }

            if (best > ans) {
                ans = best;
                k_ = k.first;
            }
            else if (best == ans) {
                k_ = min(k_, k.first);
            }
        }
        return (long long)ans * k_ % 1000000007;;
    }
};