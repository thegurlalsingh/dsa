class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < classes.size(); i++){
            int pass = classes[i][0];
            int total = classes[i][1];

            double a1 = (double)pass / total;
            double a2 = (double)(pass + 1) / (total + 1);
            pq.push({a2 - a1, i});
        }

        while(extraStudents > 0){
            auto t = pq.top();
            pq.pop();
            extraStudents--;

            int idx = t.second;
            classes[idx][0] += 1;
            classes[idx][1] += 1;

            int pass = classes[idx][0];
            int total = classes[idx][1];

            double a1 = (double)pass / total;
            double a2 = (double)(pass + 1) / (total + 1);
            pq.push({a2 - a1, idx});
        }

        double numerator = 0;
        for(int i = 0; i < classes.size(); i++){
            numerator += (double)classes[i][0] / classes[i][1];
        }

        return numerator / classes.size();
    }
};
