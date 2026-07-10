class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { 
            return a[0] < b[0]; 
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(ans.back()[1] >= intervals[i][0]){
                vector<int> t = ans.back(); ans.pop_back();
                t[0] = min(t[0], intervals[i][0]);
                t[1] = max(t[1], intervals[i][1]);
                ans.push_back(t);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};