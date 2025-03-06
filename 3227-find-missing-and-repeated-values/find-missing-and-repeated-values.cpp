class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                int key = grid[i][j];
                mp[key] += 1;
            }
        }
        int extra = 0;
        for(auto& p : mp){
            if(p.second == 2){
                extra = p.first;
                break;
            }
        }
        vector<int> arr;
        for(auto& p : mp){
            arr.push_back(p.first);
        }
        sort(arr.begin(), arr.end());
        int missing = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != i + 1){
                missing = i + 1;
                break;
            }
        }
        if(missing == 0){
            missing = *max_element(arr.begin(), arr.end()) + 1;
        }
        return {extra, missing};
    }
};