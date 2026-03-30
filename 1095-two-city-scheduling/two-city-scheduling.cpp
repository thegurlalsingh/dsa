class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int n = costs.size() / 2;
        int c = 0;

        for(int i = 0; i < n; i++){
            c += costs[i][0];  // A
        }

        for(int i = n; i < 2*n; i++){
            c += costs[i][1];  // B
        }

        return c;
    }
};