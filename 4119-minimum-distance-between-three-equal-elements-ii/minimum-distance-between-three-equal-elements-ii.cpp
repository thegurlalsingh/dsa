class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, int> mp; //elem, freq
        unordered_map<int, vector<int>> idx; //elem, idx

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            idx[nums[i]].push_back(i);
        }

        int dis = INT_MAX;
        for(auto [key, value] : mp){
            if(value >= 3){
                for(int i = 0; i < idx[key].size() - 2; i++){
                    int d = abs(idx[key][i] - idx[key][i + 1]) + abs(idx[key][i + 1] - idx[key][i + 2]) + abs(idx[key][i + 2] - idx[key][i]);
                    dis = min(dis, d);
                }
            }
        }
        return dis == INT_MAX ? -1 : dis;
    }
};