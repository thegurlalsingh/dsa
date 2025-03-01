class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                pq.push({grid[i][j], i}); 
            }
        }
        long long sum = 0;
        while(!pq.empty() && k > 0){
            int index = pq.top().second;
            if(limits[index] > 0){
                sum += pq.top().first;
                limits[index]--;
                k--;
            }
            pq.pop();
        }
        return sum;
    }
};