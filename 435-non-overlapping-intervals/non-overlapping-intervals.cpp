class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int lastEnd = intervals[0][1];
        for(int i = 1; i < intervals.size();){
            if(intervals[i][0] >= lastEnd){
                lastEnd = intervals[i][1];
                i++;
            }
            else{
                count++;
                lastEnd = min(lastEnd, intervals[i][1]);
                i++;
            }
        }
        return count;
    }
};