class Solution {
private:
    void merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;        
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = result.back();            
            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        
        intervals.clear();
        for (auto& interval : result) {
            intervals.push_back(interval);
        }
    }
    
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int count = 0;
        merge(meetings);
        for(int i = 0; i < meetings.size(); i++){
            int u = meetings[i][0];
            int v = meetings[i][1];
            count += (v - u + 1);
        }
        return (days - count);
    }
};