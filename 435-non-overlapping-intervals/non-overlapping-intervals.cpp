class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { 
            return a[1] < b[1]; 
        });

        int prev = 0;
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[prev][1] > intervals[i][0]){
                count++;
            }
            else{
                prev = i;
            }
        }

        return count;
    }
};