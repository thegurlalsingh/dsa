class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

    // sort by end time
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        return a[1] < b[1];
    });

    int count = 0;
    int prevEnd = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] < prevEnd){
            // overlap → remove current
            count++;
        } else {
            // no overlap → keep it
            prevEnd = intervals[i][1];
        }
    }
    return count;
    }
};