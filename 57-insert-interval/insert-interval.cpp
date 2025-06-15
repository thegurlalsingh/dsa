class Solution {
private:
    bool doIntervalsOverlap(vector<int>& interval1, vector<int>& interval2) {
        return interval1[1] >= interval2[0] && interval2[1] >= interval1[0];
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            return {newInterval};
        }
        vector<vector<int>> res;
        int k = 1;
        for(int i = 0; i < intervals.size(); i++){
            if(doIntervalsOverlap(intervals[i], newInterval) && (k > 0)){
                int one = min(intervals[i][0], newInterval[0]);
                int two = max(intervals[i][1], newInterval[1]);
                vector<int> insert = {one, two};
                res.push_back(insert);
                k--;
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        if(k == 1){
            res.push_back(newInterval);
        }
        sort(res.begin(), res.end());
        for (int i = 1; i < res.size(); i++) {
            if (doIntervalsOverlap(res[i - 1], res[i])) {
                res[i - 1][1] = max(res[i - 1][1], res[i][1]);
                res.erase(res.begin() + i);
                i--;
            }
        }
        return res;
    }
};