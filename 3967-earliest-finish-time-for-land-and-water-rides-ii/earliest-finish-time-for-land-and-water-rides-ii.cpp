class Solution {
    int solve(const vector<int>& start1, const vector<int>& duration1,
                                          const vector<int>& start2, const vector<int>& duration2) {
        
        int minFinish1 = INT_MAX;
        for (int i = 0; i < start1.size(); ++i) {
            minFinish1 = min(minFinish1, start1[i] + duration1[i]);
        }

        int earliestTotalFinishTime = INT_MAX;
        for (int j = 0; j < start2.size(); ++j) {
            int startTime2 = max(start2[j], minFinish1);
            int totalFinishTime = startTime2 + duration2[j];
            earliestTotalFinishTime = min(earliestTotalFinishTime, totalFinishTime);
        }
        
        return earliestTotalFinishTime;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration), solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};