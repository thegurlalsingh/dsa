class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;  
        int totalDays = 0;

        for (auto& course : courses) {
            totalDays += course[0];
            maxHeap.push(course[0]);

            if (totalDays > course[1]) {
                totalDays -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};
