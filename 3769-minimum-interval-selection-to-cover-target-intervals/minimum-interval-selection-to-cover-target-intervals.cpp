class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        sort(targetIntervals.begin(), targetIntervals.end());
        sort(availableIntervals.begin(), availableIntervals.end());
        vector<vector<int>> t;
        t.push_back(targetIntervals[0]);
        for(int i = 1; i < targetIntervals.size(); i++){
            vector<int> tback = t[t.size() - 1];
            t.pop_back();
            if(tback[1] >= targetIntervals[i][0]){
                tback[0] = min(tback[0], targetIntervals[i][0]);
                tback[1] = max(tback[1], targetIntervals[i][1]);
                t.push_back(tback);
            }
            else{
                t.push_back(tback); 
                t.push_back(targetIntervals[i]);
            }
        }

        int reach = 0;
        int count = 0;
        int j = 0;
        for(int i = 0; i < t.size(); i++){
            int s = t[i][0]; int e = t[i][1];
            while(reach < e){
                int uncovered = max(s, reach); // if we havent reached target yet, start from l else if we partially covered it then start from reach
                int far = reach;

                while(j < availableIntervals.size() && availableIntervals[j][0] <= uncovered){ // Because the next selected interval must cover the next uncovered point. Its starting point cannot be greater than that point.
                    far = max(far, availableIntervals[j][1]); // Because among all intervals that can cover the current uncovered point, we want maximum right-side coverage.
                    j++;
                }
                if(far <= reach){
                    return -1;
                }
                reach = far;
                count++;
            }
        }
        return count;
    }
};