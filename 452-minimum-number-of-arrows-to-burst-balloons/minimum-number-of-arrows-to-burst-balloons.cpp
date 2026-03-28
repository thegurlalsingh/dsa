class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;

        sort(points.begin(), points.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int count = 0;
        int prevEnd = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= prevEnd) {
                count++;
            } else {
                prevEnd = points[i][1];
            }
        }
        return points.size() - count;
    }
};