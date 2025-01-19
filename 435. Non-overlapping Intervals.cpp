class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0; 
        for (int i = 0; i < intervals.size() - 1; i++) {
            int start1 = intervals[i][0];
            int end1 = intervals[i][1];
            int start2 = intervals[i + 1][0];
            int end2 = intervals[i + 1][1];

            if (end1 > start2) {
                count++;
                if (end1 <= end2) {
                    intervals[i + 1][0] = intervals[i][0];
                    intervals[i + 1][1] = intervals[i][1];
                }
            }
        }

        return count;
    }
};
