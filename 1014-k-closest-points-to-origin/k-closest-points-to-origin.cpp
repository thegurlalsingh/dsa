typedef pair<double, pair<int, int>> P;

class Solution {
    double euclidean(int x1, int y1, int x2, int y2){
        double sqr1 = pow((x2 - x1), 2);
        double sqr2 = pow((y2 - y1), 2);
        return sqrt(sqr1 + sqr2);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < points.size(); i++){
            pq.push({euclidean(points[i][0], points[i][1], 0, 0), {points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};